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

#include "formclasswizard.h"
#include "formclasswizarddialog.h"
#include "designerconstants.h"
#include "formwindoweditor.h"
#include "qtdesignerformclasscodegenerator.h"
#include <qtsupport/qtsupportconstants.h>

#include <coreplugin/icore.h>
#include <cppeditor/cppeditorconstants.h>

#include <QDebug>
#include <QSettings>

namespace Designer {
namespace Internal {

FormClassWizard::FormClassWizard(const BaseFileWizardParameters &parameters,  QObject *parent)
  : Core::BaseFileWizard(parameters, parent)
{
}

QString FormClassWizard::headerSuffix() const
{
    return preferredSuffix(QLatin1String(CppEditor::Constants::CPP_HEADER_MIMETYPE));
}

QString FormClassWizard::sourceSuffix() const
{
    return preferredSuffix(QLatin1String(CppEditor::Constants::CPP_SOURCE_MIMETYPE));
}

QString FormClassWizard::formSuffix() const
{
    return preferredSuffix(QLatin1String(Constants::FORM_MIMETYPE));
}

Core::FeatureSet FormClassWizard::requiredFeatures() const
{
    return Core::Feature(QtSupport::Constants::FEATURE_QWIDGETS);
}

QWizard *FormClassWizard::createWizardDialog(QWidget *parent,
                                             const Core::WizardDialogParameters &wizardDialogParameters) const
{
    FormClassWizardDialog *wizardDialog = new FormClassWizardDialog(wizardDialogParameters.extensionPages(),
                                                                    parent);
    wizardDialog->setPath(wizardDialogParameters.defaultPath());
    return wizardDialog;
}

Core::GeneratedFiles FormClassWizard::generateFiles(const QWizard *w, QString *errorMessage) const
{
    const FormClassWizardDialog *wizardDialog = qobject_cast<const FormClassWizardDialog *>(w);
    const Designer::FormClassWizardParameters params = wizardDialog->parameters();

    if (params.uiTemplate.isEmpty()) {
        *errorMessage = QLatin1String("Internal error: FormClassWizard::generateFiles: empty template contents");
        return Core::GeneratedFiles();
    }

    // header
    const QString formFileName = buildFileName(params.path, params.uiFile, formSuffix());
    const QString headerFileName = buildFileName(params.path, params.headerFile, headerSuffix());
    const QString sourceFileName = buildFileName(params.path, params.sourceFile, sourceSuffix());

    Core::GeneratedFile headerFile(headerFileName);
    headerFile.setAttributes(Core::GeneratedFile::OpenEditorAttribute);

    // Source
    Core::GeneratedFile sourceFile(sourceFileName);
    sourceFile.setAttributes(Core::GeneratedFile::OpenEditorAttribute);

    // UI
    Core::GeneratedFile uiFile(formFileName);
    uiFile.setContents(params.uiTemplate);
    uiFile.setAttributes(Core::GeneratedFile::OpenEditorAttribute);

    QString source, header;

    QtDesignerFormClassCodeGenerator::generateCpp(params, &header, &source);
    sourceFile.setContents(source);
    headerFile.setContents(header);

    if (Designer::Constants::Internal::debug)
        qDebug() << Q_FUNC_INFO << '\n' << header << '\n' << source;

    return  Core::GeneratedFiles() << headerFile << sourceFile << uiFile;
}

}
}
