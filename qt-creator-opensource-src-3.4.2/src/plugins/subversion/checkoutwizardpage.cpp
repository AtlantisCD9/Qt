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

#include "checkoutwizardpage.h"

#include <QCheckBox>

namespace Subversion {
namespace Internal {

CheckoutWizardPage::CheckoutWizardPage(QWidget *parent) :
    VcsBase::BaseCheckoutWizardPage(parent),
    m_trustServerCertBox(new QCheckBox(tr("Trust Server Certificate")))
{
    setTitle(tr("Location"));
    setSubTitle(tr("Specify repository URL, checkout directory and path."));
    setRepositoryLabel(tr("Repository:"));
    setBranchSelectorVisible(false);

    addLocalControl(m_trustServerCertBox);
}

bool CheckoutWizardPage::trustServerCert() const
{
    return m_trustServerCertBox->isChecked();
}

QString CheckoutWizardPage::directoryFromRepository(const QString &repoIn) const
{
    /* Try to figure out a good directory name from something like:
     * "svn://<server>/path1/project" -> project */

    QString repo = repoIn.trimmed();
    const QChar slash = QLatin1Char('/');
    // remove host
    const int slashPos = repo.lastIndexOf(slash);
    if (slashPos != -1)
        repo.remove(0, slashPos + 1);
    // fix invalid characters
    repo.replace(QLatin1Char('.'), QLatin1Char('-'));
    return repo;
}

} // namespace Internal
} // namespace Subversion
