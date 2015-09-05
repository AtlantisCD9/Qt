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

#ifndef TESTWIZARDDIALOG_H
#define TESTWIZARDDIALOG_H

#include "qtwizard.h"

namespace Qt4ProjectManager {
namespace Internal {

class TestWizardPage;

// Parameters of the test wizard.
struct TestWizardParameters {
    enum { requiresQApplicationDefault = 0 };

    static const char *filePrefix;

    TestWizardParameters();


    enum Type { Test, Benchmark };

    Type type;
    bool initializationCode;
    bool useDataSet;
    bool requiresQApplication;

    QString className;
    QString testSlot;
    QString fileName;
};

class TestWizardDialog : public BaseQt4ProjectWizardDialog
{
    Q_OBJECT
public:
    explicit TestWizardDialog(const QString &templateName,
                              const QIcon &icon,
                              QWidget *parent,
                              const Core::WizardDialogParameters &parameters);

    TestWizardParameters testParameters() const;
    QtProjectParameters projectParameters() const;

private slots:
    void slotCurrentIdChanged(int id);

private:
    TestWizardPage *m_testPage;
    int m_testPageId;
    int m_modulesPageId;
};

} // namespace Internal
} // namespace Qt4ProjectManager

#endif // TESTWIZARDDIALOG_H
