/**************************************************************************
**
** Copyright (C) 2015 Hugues Delorme
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

#include "clonewizardpage.h"
#include "cloneoptionspanel.h"

using namespace Bazaar::Internal;

CloneWizardPage::CloneWizardPage(QWidget *parent)
    : VcsBase::BaseCheckoutWizardPage(parent),
      m_optionsPanel(new CloneOptionsPanel)
{
    setTitle(tr("Location"));
    setSubTitle(tr("Specify repository URL, clone directory and path."));
    setRepositoryLabel(tr("Clone URL:"));
    setBranchSelectorVisible(false);
    addLocalControl(m_optionsPanel);
}

const CloneOptionsPanel *CloneWizardPage::cloneOptionsPanel() const
{
    return m_optionsPanel;
}

QString CloneWizardPage::directoryFromRepository(const QString &repository) const
{
    // Bazaar repositories are generally of the form
    // 'lp:project' or 'protocol://repositoryUrl/repository/'
    // We are just looking for repository.
    QString repo = repository.trimmed();
    if (repo.startsWith(QLatin1String("lp:")))
        return repo.mid(3);
    const QChar slash = QLatin1Char('/');
    if (repo.endsWith(slash))
        repo.truncate(repo.size() - 1);
    // Take the basename or the repository url
    return repo.mid(repo.lastIndexOf(slash) + 1);
}
