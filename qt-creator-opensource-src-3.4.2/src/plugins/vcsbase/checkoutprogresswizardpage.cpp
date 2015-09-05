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

#include "checkoutprogresswizardpage.h"
#include "vcscommand.h"
#include "vcsbaseplugin.h"

#include <utils/outputformatter.h>
#include <utils/qtcassert.h>

#include <QApplication>
#include <QLabel>
#include <QPlainTextEdit>
#include <QVBoxLayout>

/*!
    \class VcsBase::Internal::CheckoutProgressWizardPage

    \brief The CheckoutProgressWizardPage implements a page showing the
    progress of an initial project checkout.

    Turns complete when the job succeeds.

    \sa VcsBase::BaseCheckoutWizard
*/

namespace VcsBase {
namespace Internal {

CheckoutProgressWizardPage::CheckoutProgressWizardPage(QWidget *parent) :
    QWizardPage(parent),
    m_startedStatus(tr("Checkout started...")),
    m_overwriteOutput(false),
    m_state(Idle)
{
    resize(264, 200);
    auto verticalLayout = new QVBoxLayout(this);
    m_logPlainTextEdit = new QPlainTextEdit;
    m_formatter = new Utils::OutputFormatter;
    m_logPlainTextEdit->setReadOnly(true);
    m_formatter->setPlainTextEdit(m_logPlainTextEdit);

    verticalLayout->addWidget(m_logPlainTextEdit);

    m_statusLabel = new QLabel;
    verticalLayout->addWidget(m_statusLabel);
    setTitle(tr("Checkout"));
}

CheckoutProgressWizardPage::~CheckoutProgressWizardPage()
{
    QTC_ASSERT(m_state != Running, QApplication::restoreOverrideCursor());
    delete m_formatter;
}

void CheckoutProgressWizardPage::setStartedStatus(const QString &startedStatus)
{
    m_startedStatus = startedStatus;
}

void CheckoutProgressWizardPage::start(VcsCommand *command)
{
    if (!command) {
        m_logPlainTextEdit->setPlainText(tr("No job running, please abort."));
        return;
    }

    QTC_ASSERT(m_state != Running, return);
    m_command = command;
    command->setProgressiveOutput(true);
    connect(command, &VcsCommand::output, this, &CheckoutProgressWizardPage::reportStdOut);
    connect(command, &VcsCommand::errorText, this, &CheckoutProgressWizardPage::reportStdErr);
    connect(command, &VcsCommand::finished, this, &CheckoutProgressWizardPage::slotFinished);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    m_logPlainTextEdit->clear();
    m_overwriteOutput = false;
    m_statusLabel->setText(m_startedStatus);
    m_statusLabel->setPalette(QPalette());
    m_state = Running;
    command->execute();
}

void CheckoutProgressWizardPage::slotFinished(bool ok, int exitCode, const QVariant &)
{
    QTC_ASSERT(m_state == Running, return);

    const bool success = (ok && exitCode == 0);
    QString message;
    QPalette palette;

    if (success) {
        m_state = Succeeded;
        message = tr("Succeeded.");
        palette.setColor(QPalette::Active, QPalette::Text, Qt::green);
    } else {
        m_state = Failed;
        message = tr("Failed.");
        palette.setColor(QPalette::Active, QPalette::Text, Qt::red);
    }

    m_statusLabel->setText(message);
    m_statusLabel->setPalette(palette);

    QApplication::restoreOverrideCursor();

    if (success)
        emit completeChanged();
    emit terminated(success);
}

void CheckoutProgressWizardPage::reportStdOut(const QString &text)
{
    m_formatter->appendMessage(text, Utils::StdOutFormat);
}

void CheckoutProgressWizardPage::reportStdErr(const QString &text)
{
    m_formatter->appendMessage(text, Utils::StdErrFormat);
}

void CheckoutProgressWizardPage::terminate()
{
    if (m_command)
        m_command->cancel();
}

bool CheckoutProgressWizardPage::isComplete() const
{
    return m_state == Succeeded;
}

} // namespace Internal
} // namespace VcsBase
