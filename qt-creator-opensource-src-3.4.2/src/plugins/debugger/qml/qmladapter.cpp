/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company.  For licensing terms and
** conditions see http://www.qt.io/terms-conditions.  For further information
** use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file.  Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, The Qt Company gives you certain additional
** rights.  These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#include "qmladapter.h"

#include <debugger/debuggerstringutils.h>
#include "qmlengine.h"
#include "qmlv8debuggerclient.h"
#include "qscriptdebuggerclient.h"

#include <utils/qtcassert.h>

#include <QDebug>

using namespace QmlDebug;

namespace Debugger {
namespace Internal {

/*!
 QmlAdapter manages the connection & clients for QML/JS debugging.
 */

QmlAdapter::QmlAdapter(DebuggerEngine *engine, QObject *parent)
    : QObject(parent)
    , m_engine(engine)
    , m_qmlClient(0)
    , m_conn(0)
    , m_msgClient(0)
{
    m_connectionTimer.setInterval(4000);
    m_connectionTimer.setSingleShot(true);
    connect(&m_connectionTimer, &QTimer::timeout, this, &QmlAdapter::checkConnectionState);

    m_conn = new QmlDebugConnection(this);
    connect(m_conn, &QmlDebugConnection::stateMessage,
            this, &QmlAdapter::showConnectionStateMessage);
    connect(m_conn, &QmlDebugConnection::errorMessage,
            this, &QmlAdapter::showConnectionErrorMessage);
    connect(m_conn, &QmlDebugConnection::error,
            this, &QmlAdapter::connectionErrorOccurred);
    connect(m_conn, &QmlDebugConnection::opened,
            &m_connectionTimer, &QTimer::stop);
    connect(m_conn, &QmlDebugConnection::opened,
            this, &QmlAdapter::connected);
    connect(m_conn, &QmlDebugConnection::closed,
            this, &QmlAdapter::disconnected);

    createDebuggerClients();
    m_msgClient = new QDebugMessageClient(m_conn);
    connect(m_msgClient, &QDebugMessageClient::newState, this, &QmlAdapter::clientStateChanged);

}

QmlAdapter::~QmlAdapter()
{
}

void QmlAdapter::beginConnectionTcp(const QString &address, quint16 port)
{
    if (m_engine.isNull() || !m_conn || m_conn->isOpen())
        return;

    m_conn->connectToHost(address, port);

    //A timeout to check the connection state
    m_connectionTimer.start();
}

void QmlAdapter::closeConnection()
{
    if (m_connectionTimer.isActive()) {
        m_connectionTimer.stop();
    } else {
        if (m_conn)
            m_conn->close();
    }
}

void QmlAdapter::connectionErrorOccurred(QDebugSupport::Error error)
{
    // this is only an error if we are already connected and something goes wrong.
    if (isConnected()) {
        emit connectionError(error);
    } else {
        m_connectionTimer.stop();
        emit connectionStartupFailed();
    }
}

void QmlAdapter::clientStateChanged(QmlDebugClient::State state)
{
    QString serviceName;
    float version = 0;
    if (QmlDebugClient *client = qobject_cast<QmlDebugClient*>(sender())) {
        serviceName = client->name();
        version = client->remoteVersion();
    }

    logServiceStateChange(serviceName, version, state);
}

void QmlAdapter::debugClientStateChanged(QmlDebugClient::State state)
{
    if (state != QmlDebugClient::Enabled)
        return;
    QmlDebugClient *client = qobject_cast<QmlDebugClient*>(sender());
    QTC_ASSERT(client, return);

    m_qmlClient = qobject_cast<BaseQmlDebuggerClient *>(client);
    m_qmlClient->startSession();
}

void QmlAdapter::checkConnectionState()
{
    if (!isConnected()) {
        closeConnection();
        emit connectionStartupFailed();
    }
}

bool QmlAdapter::isConnected() const
{
    return m_conn && m_qmlClient && m_conn->isOpen();
}

void QmlAdapter::createDebuggerClients()
{
    QScriptDebuggerClient *debugClient1 = new QScriptDebuggerClient(m_conn);
    connect(debugClient1, &QScriptDebuggerClient::newState,
            this, &QmlAdapter::clientStateChanged);
    connect(debugClient1, &QScriptDebuggerClient::newState,
            this, &QmlAdapter::debugClientStateChanged);

    QmlV8DebuggerClient *debugClient2 = new QmlV8DebuggerClient(m_conn);
    connect(debugClient2, &QmlV8DebuggerClient::newState,
            this, &QmlAdapter::clientStateChanged);
    connect(debugClient2, &QmlV8DebuggerClient::newState,
            this, &QmlAdapter::debugClientStateChanged);

    m_debugClients.insert(debugClient1->name(),debugClient1);
    m_debugClients.insert(debugClient2->name(),debugClient2);

    debugClient1->setEngine((QmlEngine*)(m_engine.data()));
    debugClient2->setEngine((QmlEngine*)(m_engine.data()));
}

QmlDebugConnection *QmlAdapter::connection() const
{
    return m_conn;
}

DebuggerEngine *QmlAdapter::debuggerEngine() const
{
    return m_engine.data();
}

void QmlAdapter::showConnectionStateMessage(const QString &message)
{
    if (!m_engine.isNull())
        m_engine.data()->showMessage(_("QML Debugger: ") + message, LogStatus);
}

void QmlAdapter::showConnectionErrorMessage(const QString &message)
{
    if (!m_engine.isNull())
        m_engine.data()->showMessage(_("QML Debugger: ") + message, LogError);
}

BaseQmlDebuggerClient *QmlAdapter::activeDebuggerClient() const
{
    return m_qmlClient;
}

QHash<QString, BaseQmlDebuggerClient*> QmlAdapter::debuggerClients() const
{
    return m_debugClients;
}

QDebugMessageClient *QmlAdapter::messageClient() const
{
    return m_msgClient;
}

void QmlAdapter::logServiceStateChange(const QString &service, float version,
                                        QmlDebugClient::State newState)
{
    switch (newState) {
    case QmlDebugClient::Unavailable: {
        showConnectionStateMessage(_("Status of \"%1\" Version: %2 changed to 'unavailable'.").
                                    arg(service).arg(QString::number(version)));
        break;
    }
    case QmlDebugClient::Enabled: {
        showConnectionStateMessage(_("Status of \"%1\" Version: %2 changed to 'enabled'.").
                                    arg(service).arg(QString::number(version)));
        break;
    }

    case QmlDebugClient::NotConnected: {
        showConnectionStateMessage(_("Status of \"%1\" Version: %2 changed to 'not connected'.").
                                    arg(service).arg(QString::number(version)));
        break;
    }
    }
}

void QmlAdapter::logServiceActivity(const QString &service, const QString &logMessage)
{
    if (!m_engine.isNull())
        m_engine.data()->showMessage(service + QLatin1Char(' ') + logMessage, LogDebug);
}

} // namespace Internal
} // namespace Debugger
