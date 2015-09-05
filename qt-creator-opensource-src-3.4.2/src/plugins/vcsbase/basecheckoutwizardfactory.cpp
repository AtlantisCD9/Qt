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

#include "basecheckoutwizardfactory.h"
#include "basecheckoutwizard.h"

#include <coreplugin/icontext.h>
#include <coreplugin/icore.h>
#include <coreplugin/featureprovider.h>

#include <projectexplorer/projectexplorer.h>

#include <utils/fileutils.h>
#include <utils/qtcassert.h>

#include <QCoreApplication>
#include <QDir>
#include <QMessageBox>
#include <QScopedPointer>

/*!
    \class VcsBase::BaseCheckoutWizard

    \brief The BaseCheckoutWizard class implements a wizard for initially
    checking out a project using a version control system.

   Implements all of Core::IWizard with the exception of
   name()/description() and icon().

   Pops up a QWizard consisting of a Parameter Page which is created
   by a virtual factory function and a progress
   page containing a log text. The factory function createJob()
   creates a job with the output connected to the log window,
   returning the path to the checkout.

   On success, the wizard tries to locate a project file
   and open it.

   \sa VcsBase::BaseCheckoutWizardPage
*/

namespace VcsBase {

BaseCheckoutWizardFactory::BaseCheckoutWizardFactory()
{
    setWizardKind(IWizardFactory::ProjectWizard);
    setCategory(QLatin1String(ProjectExplorer::Constants::IMPORT_WIZARD_CATEGORY));
    setDisplayCategory(QCoreApplication::translate("ProjectExplorer",
        ProjectExplorer::Constants::IMPORT_WIZARD_CATEGORY_DISPLAY));
    setFlags(Core::IWizardFactory::PlatformIndependent);
}

void BaseCheckoutWizardFactory::runWizard(const QString &path, QWidget *parent, const QString &platform,
                                   const QVariantMap &extraValues)
{
    Q_UNUSED(platform);
    Q_UNUSED(extraValues);
    // Create dialog and launch

    Utils::FileName checkoutPath;
    {
        QScopedPointer<BaseCheckoutWizard> wizard(m_wizardCreator(Utils::FileName::fromString(path), parent));
        wizard->setWindowTitle(displayName());
        Core::ICore::registerWindow(wizard.data(), Core::Context("New.CheckoutWizard"));
        checkoutPath = wizard->run();
    }

    if (checkoutPath.isEmpty())
        return;

    // Now try to find the project file and open
    QString errorMessage;
    const QString projectFile = openProject(checkoutPath, &errorMessage);
    if (projectFile.isEmpty()) {
        QMessageBox msgBox(QMessageBox::Warning, tr("Cannot Open Project"),
                           tr("Failed to open project in \"%1\".").arg(checkoutPath.toUserOutput()));
        msgBox.setDetailedText(errorMessage);
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
    }
}

static inline QString msgNoProjectFiles(const QDir &dir, const QStringList &patterns)
{
    return BaseCheckoutWizardFactory::tr("Could not find any project files matching (%1) in the directory \"%2\".").arg(patterns.join(QLatin1String(", ")), QDir::toNativeSeparators(dir.absolutePath()));
}

// Try to find the project files in a project directory with some smartness
static QFileInfoList findProjectFiles(const QDir &projectDir, QString *errorMessage)
{
    const QStringList projectFilePatterns = ProjectExplorer::ProjectExplorerPlugin::projectFilePatterns();
    // Project directory
    QFileInfoList projectFiles = projectDir.entryInfoList(projectFilePatterns, QDir::Files|QDir::NoDotAndDotDot|QDir::Readable);
    if (!projectFiles.empty())
        return projectFiles;
    // Try a 'src' directory
    QFileInfoList srcDirs = projectDir.entryInfoList(QStringList(QLatin1String("src")), QDir::Dirs|QDir::NoDotAndDotDot|QDir::Readable);
    if (srcDirs.empty()) {
        *errorMessage = msgNoProjectFiles(projectDir, projectFilePatterns);
        return QFileInfoList();
    }
    const QDir srcDir = QDir(srcDirs.front().absoluteFilePath());
    projectFiles = srcDir.entryInfoList(projectFilePatterns, QDir::Files|QDir::NoDotAndDotDot|QDir::Readable);
    if (projectFiles.empty()) {
        *errorMessage = msgNoProjectFiles(srcDir, projectFilePatterns);
        return QFileInfoList();
    }
    return projectFiles;
}

QString BaseCheckoutWizardFactory::openProject(const Utils::FileName &path, QString *errorMessage)
{
    // Search the directory for project files
    const QDir dir(path.toString());
    if (!dir.exists()) {
        *errorMessage = tr("\"%1\" does not exist.").
                        arg(path.toUserOutput()); // Should not happen
        return QString();
    }
    QFileInfoList projectFiles = findProjectFiles(dir, errorMessage);
    if (projectFiles.empty())
        return QString();
    // Open. Do not use a busy cursor here as additional wizards might pop up
    const QString projectFile = projectFiles.front().absoluteFilePath();
    if (!ProjectExplorer::ProjectExplorerPlugin::instance()->openProject(projectFile, errorMessage))
        return QString();

    return projectFile;
}

void BaseCheckoutWizardFactory::setWizardCreator(const BaseCheckoutWizardFactory::WizardCreator &creator)
{
    m_wizardCreator = creator;
}

} // namespace VcsBase
