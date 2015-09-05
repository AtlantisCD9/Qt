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

#ifndef QTQUICKAPP_H
#define QTQUICKAPP_H

#include "abstractmobileapp.h"

#include <QStringList>

namespace QmakeProjectManager {
namespace Internal {

struct QtQuickAppGeneratedFileInfo : public AbstractGeneratedFileInfo
{
    enum ExtendedFileType {
        MainQmlFile = ExtendedFile,
        MainQrcFile,
        AppViewerPriFile,
        AppViewerCppFile,
        AppViewerHFile,
        QrcDeploymentFile
    };

    QtQuickAppGeneratedFileInfo() : AbstractGeneratedFileInfo() {}
};

class TemplateInfo
{
public:
    TemplateInfo() : stubVersionMinor(9) {}
    QString templateName;
    QString templatePath;
    QString displayName;
    QString description;
    QString openFile;
    QString featuresRequired;
    QString priority;
    QString viewerClassName;
    QString viewerDir;
    QString qrcDeployment;
    QStringList requiredPlugins;
    int stubVersionMinor;
};

class QtQuickApp : public AbstractMobileApp
{
public:
    enum ExtendedFileType {
        MainQml = ExtendedFile,
        MainQmlOrigin,
        MainQrc,
        MainQrcOrigin,
        AppViewerPri,
        AppViewerPriOrigin,
        AppViewerCpp,
        AppViewerCppOrigin,
        AppViewerH,
        AppViewerHOrigin,
        QrcDeployment,
        QrcDeploymentOrigin
    };

    QtQuickApp();

    static QList<TemplateInfo> templateInfos();

    void setTemplateInfo(const TemplateInfo &templateInfo);

#ifndef CREATORLESSTEST
    virtual Core::GeneratedFiles generateFiles(QString *errorMessage) const;
#else
    bool generateFiles(QString *errorMessage) const;
#endif // CREATORLESSTEST
    bool useExistingMainQml() const;

    static const int StubVersion;

protected:
    virtual QByteArray generateProFile(QString *errorMessage) const;

    QString appViewerBaseName() const;
    QString qrcDeployment() const;
    QString fileName(ExtendedFileType type) const;
    QString appViewerOriginSubDir() const;

private:
    virtual QByteArray generateFileExtended(int fileType,
        bool *versionAndCheckSum, QString *comment, QString *errorMessage) const;
    virtual QString pathExtended(int fileType) const;
    virtual QString originsRoot() const;
    virtual QString mainWindowClassName() const;
    virtual int stubVersionMinor() const;
    virtual bool adaptCurrentMainCppTemplateLine(QString &line) const;
    virtual void handleCurrentProFileTemplateLine(const QString &line,
        QTextStream &proFileTemplate, QTextStream &proFile,
        bool &commentOutNextLine) const;
    QList<AbstractGeneratedFileInfo> updateableFiles(const QString &mainProFile) const;
    QList<DeploymentFolder> deploymentFolders() const;

    QFileInfo m_mainQmlFile;
    TemplateInfo m_templateInfo;
};

} // namespace Internal
} // namespace QmakeProjectManager

#endif // QTQUICKAPP_H
