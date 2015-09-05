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

#ifndef ABSTRACTMOBILEAPPWIZARD_H
#define ABSTRACTMOBILEAPPWIZARD_H

#include <qmakeprojectmanager/qmakeprojectmanager_global.h>
#include <projectexplorer/baseprojectwizarddialog.h>
#include <qtsupport/baseqtversion.h>

namespace ProjectExplorer { class TargetSetupPage; }

namespace QtSupport { class QtVersionNumber; }

namespace QmakeProjectManager {

class AbstractMobileApp;

/// \internal
class QMAKEPROJECTMANAGER_EXPORT AbstractMobileAppWizardDialog : public ProjectExplorer::BaseProjectWizardDialog
{
    Q_OBJECT

protected:
    explicit AbstractMobileAppWizardDialog(QWidget *parent, const QtSupport::QtVersionNumber &minimumQtVersionNumber,
                                           const QtSupport::QtVersionNumber &maximumQtVersionNumber,
                                           const Core::WizardDialogParameters &parameters);
public:
    ProjectExplorer::TargetSetupPage *kitsPage() const;

protected:
    void addKitsPage();
    void updateKitsPage();

private:
    ProjectExplorer::TargetSetupPage *m_kitsPage;
    const QtSupport::QtVersionNumber m_minimumQtVersionNumber;
    const QtSupport::QtVersionNumber m_maximumQtVersionNumber;
};

/// \internal
class QMAKEPROJECTMANAGER_EXPORT AbstractMobileAppWizard : public Core::BaseFileWizardFactory
{
    Q_OBJECT

private slots:
    void useProjectPath(const QString &projectName, const QString &projectPath);

protected:
    virtual QString fileToOpenPostGeneration() const = 0;

private:
    Core::BaseFileWizard *create(QWidget *parent, const Core::WizardDialogParameters &parameters) const;
    Core::GeneratedFiles generateFiles(const QWizard *wizard, QString *errorMessage) const;
    bool postGenerateFiles(const QWizard *w, const Core::GeneratedFiles &l, QString *errorMessage);

    virtual AbstractMobileApp *app() const = 0;
    virtual AbstractMobileAppWizardDialog *wizardDialog() const = 0;
    virtual AbstractMobileAppWizardDialog *createInternal(QWidget *parent,
                                                          const Core::WizardDialogParameters &parameters) const = 0;
    virtual void projectPathChanged(const QString &path) const = 0;
    virtual void prepareGenerateFiles(const QWizard *wizard, QString *errorMessage) const = 0;
};

} // namespace QmakeProjectManager

#endif // ABSTRACTMOBILEAPPWIZARD_H
