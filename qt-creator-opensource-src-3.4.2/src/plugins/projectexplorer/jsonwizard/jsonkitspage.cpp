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

#include "jsonkitspage.h"
#include "jsonwizard.h"

#include "../iprojectmanager.h"
#include "../kit.h"
#include "../project.h"
#include "../projectexplorer.h"

#include <coreplugin/featureprovider.h>

#include <extensionsystem/pluginmanager.h>

#include <utils/algorithm.h>
#include <utils/macroexpander.h>
#include <utils/mimetypes/mimedatabase.h>
#include <utils/qtcassert.h>

namespace ProjectExplorer {

JsonKitsPage::JsonKitsPage(QWidget *parent) : TargetSetupPage(parent)
{ }

void JsonKitsPage::initializePage()
{
    JsonWizard *wiz = qobject_cast<JsonWizard *>(wizard());
    QTC_ASSERT(wiz, return);

    connect(wiz, &JsonWizard::filesReady, this, &JsonKitsPage::setupProjectFiles);

    const QString platform = wiz->stringValue(QLatin1String("Platform"));
    const Core::FeatureSet preferred = Core::FeatureSet::fromStringList(wiz->value(QLatin1String("PreferredFeatures")).toStringList());
    const Core::FeatureSet required = Core::FeatureSet::fromStringList(wiz->value(QLatin1String("RequiredFeatures")).toStringList());

    setRequiredKitMatcher(KitMatcher([required](const Kit *k) { return k->hasFeatures(required); }));
    setPreferredKitMatcher(KitMatcher([platform, preferred](const Kit *k) { return k->hasPlatform(platform) && k->hasFeatures(preferred); }));
    setProjectPath(wiz->expander()->expand(unexpandedProjectPath()));

    TargetSetupPage::initializePage();
}

void JsonKitsPage::cleanupPage()
{
    JsonWizard *wiz = qobject_cast<JsonWizard *>(wizard());
    QTC_ASSERT(wiz, return);

    disconnect(wiz, &JsonWizard::filesReady, this, 0);

    TargetSetupPage::cleanupPage();
}

void JsonKitsPage::setUnexpandedProjectPath(const QString &path)
{
    m_unexpandedProjectPath = path;
}

QString JsonKitsPage::unexpandedProjectPath() const
{
    return m_unexpandedProjectPath;
}

void JsonKitsPage::setupProjectFiles(const JsonWizard::GeneratorFiles &files)
{
    Project *project = 0;
    QList<IProjectManager *> managerList = ExtensionSystem::PluginManager::getObjects<IProjectManager>();

    foreach (const JsonWizard::GeneratorFile &f, files) {
        if (f.file.attributes() & Core::GeneratedFile::OpenProjectAttribute) {
            QString errorMessage;
            QString path = f.file.path();
            const QFileInfo fi(path);

            if (fi.exists())
                path = fi.canonicalFilePath();

            Utils::MimeDatabase mdb;
            Utils::MimeType mt = mdb.mimeTypeForFile(fi);
            if (!mt.isValid())
                continue;

            auto manager = Utils::findOrDefault(managerList, Utils::equal(&IProjectManager::mimeType, mt.name()));
            project = manager ? manager->openProject(path, &errorMessage) : 0;
            if (project) {
                if (setupProject(project))
                    project->saveSettings();
                delete project;
                project = 0;
            }
        }
    }
}

} // namespace ProjectExplorer
