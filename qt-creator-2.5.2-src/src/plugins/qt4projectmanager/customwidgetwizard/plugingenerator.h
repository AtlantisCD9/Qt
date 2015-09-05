/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2012 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
**
** GNU Lesser General Public License Usage
**
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this file.
** Please review the following information to ensure the GNU Lesser General
** Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** Other Usage
**
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**************************************************************************/

#ifndef PLUGINGENERATOR_H
#define PLUGINGENERATOR_H

#include <QObject>
#include <QString>
#include <QList>
#include <QMap>

QT_BEGIN_NAMESPACE
class QWidget;
QT_END_NAMESPACE

namespace Core {
    class GeneratedFile;
}

namespace Qt4ProjectManager {
namespace Internal {

struct PluginOptions;

struct GenerationParameters {
    QString path;
    QString fileName;
    QString templatePath;
};

class PluginGenerator : public QObject
{
    Q_OBJECT

public:
    static QList<Core::GeneratedFile> generatePlugin(const GenerationParameters& p,
                                                     const PluginOptions &options,
                                                     QString *errorMessage);

private:
    typedef QMap<QString,QString> SubstitutionMap;
    static QString processTemplate(const QString &tmpl, const SubstitutionMap &substMap, QString *errorMessage);
    static QString cStringQuote(QString s);
};

}
}

#endif