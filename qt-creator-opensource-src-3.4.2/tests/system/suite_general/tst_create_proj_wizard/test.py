#############################################################################
##
## Copyright (C) 2015 The Qt Company Ltd.
## Contact: http://www.qt.io/licensing
##
## This file is part of Qt Creator.
##
## Commercial License Usage
## Licensees holding valid commercial Qt licenses may use this file in
## accordance with the commercial license agreement provided with the
## Software or, alternatively, in accordance with the terms contained in
## a written agreement between you and The Qt Company.  For licensing terms and
## conditions see http://www.qt.io/terms-conditions.  For further information
## use the contact form at http://www.qt.io/contact-us.
##
## GNU Lesser General Public License Usage
## Alternatively, this file may be used under the terms of the GNU Lesser
## General Public License version 2.1 or version 3 as published by the Free
## Software Foundation and appearing in the file LICENSE.LGPLv21 and
## LICENSE.LGPLv3 included in the packaging of this file.  Please review the
## following information to ensure the GNU Lesser General Public License
## requirements will be met: https://www.gnu.org/licenses/lgpl.html and
## http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
##
## In addition, as a special exception, The Qt Company gives you certain additional
## rights.  These rights are described in The Qt Company LGPL Exception
## version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
##
#############################################################################

source("../../shared/qtcreator.py")

import re

def main():
    global tmpSettingsDir
    quickCombinations = ["1.1", "2.1", "2.2", "2.3", "2.4",
                         "Controls 1.0", "Controls 1.1", "Controls 1.2", "Controls 1.3"]
    startApplication("qtcreator" + SettingsPath)
    if not startedWithoutPluginError():
        return
    kits = getConfiguredKits()
    test.log("Collecting potential project types...")
    availableProjectTypes = []
    invokeMenuItem("File", "New File or Project...")
    categoriesView = waitForObject(":New.templateCategoryView_QTreeView")
    catModel = categoriesView.model()
    projects = catModel.index(0, 0)
    test.compare("Projects", str(projects.data()))
    comboBox = findObject(":New.comboBox_QComboBox")
    targets = zip(*kits.values())[0]
    test.verify(comboBox.enabled, "Verifying whether combobox is enabled.")
    test.compare(comboBox.currentText, "Desktop Templates")
    selectFromCombo(comboBox, "All Templates")
    for category in [item.replace(".", "\\.") for item in dumpItems(catModel, projects)]:
        # skip non-configurable
        if "Import" in category:
            continue
        clickItem(categoriesView, "Projects." + category, 5, 5, 0, Qt.LeftButton)
        templatesView = waitForObject("{name='templatesView' type='QListView' visible='1'}")
        # needed because categoriesView and templatesView using same model
        for template in dumpItems(templatesView.model(), templatesView.rootIndex()):
            template = template.replace(".", "\\.")
            # skip non-configurable
            if (template != "Qt Quick UI" and "(CMake Build)" not in template
                and "(Qbs Build)" not in template):
                availableProjectTypes.append({category:template})
    clickButton(waitForObject("{text='Cancel' type='QPushButton' unnamed='1' visible='1'}"))
    for current in availableProjectTypes:
        category = current.keys()[0]
        template = current.values()[0]
        displayedPlatforms = __createProject__(category, template)
        if template == "Qt Quick Application":
            for counter, qComb in enumerate(quickCombinations):
                requiredQtVersion = __createProjectHandleQtQuickSelection__(qComb)
                __modifyAvailableTargets__(displayedPlatforms, requiredQtVersion, True)
                verifyKitCheckboxes(kits, displayedPlatforms)
                # FIXME: if QTBUG-35203 is fixed replace by triggering the shortcut for Back
                clickButton(waitForObject("{type='QPushButton' text='Cancel' visible='1'}"))
                # are there more Quick combinations - then recreate this project
                if counter < len(quickCombinations) - 1:
                    displayedPlatforms = __createProject__(category, template)
            continue
        verifyKitCheckboxes(kits, displayedPlatforms)
        clickButton(waitForObject("{type='QPushButton' text='Cancel' visible='1'}"))
    invokeMenuItem("File", "Exit")

def verifyKitCheckboxes(kits, displayedPlatforms):
    waitForObject("{type='QLabel' unnamed='1' visible='1' text='Kit Selection'}")
    availableCheckboxes = filter(visibleCheckBoxExists, kits.keys())
    # verification whether expected, found and configured match
    for t in kits:
        if t in displayedPlatforms:
            if t in availableCheckboxes:
                test.passes("Found expected kit '%s' on 'Kit Selection' page." % t)
                availableCheckboxes.remove(t)
            else:
                test.fail("Expected kit '%s' missing on 'Kit Selection' page." % t)
        else:
            if t in availableCheckboxes:
                test.fail("Kit '%s' found on 'Kit Selection' page - but was not expected!" % t)
            else:
                test.passes("Irrelevant kit '%s' not found on 'Kit Selection' page." % t)
    if len(availableCheckboxes) != 0:
        test.fail("Found unexpected additional kit(s) %s on 'Kit Selection' page."
                  % str(availableCheckboxes))

def __createProject__(category, template):
    invokeMenuItem("File", "New File or Project...")
    selectFromCombo(waitForObject(":New.comboBox_QComboBox"), "All Templates")
    categoriesView = waitForObject(":New.templateCategoryView_QTreeView")
    clickItem(categoriesView, "Projects." + category, 5, 5, 0, Qt.LeftButton)
    templatesView = waitForObject("{name='templatesView' type='QListView' visible='1'}")
    test.log("Verifying '%s' -> '%s'" % (category.replace("\\.", "."), template.replace("\\.", ".")))
    textBrowser = findObject(":frame.templateDescription_QTextBrowser")
    origTxt = str(textBrowser.plainText)
    clickItem(templatesView, template, 5, 5, 0, Qt.LeftButton)
    waitFor("origTxt != str(textBrowser.plainText)", 2000)
    displayedPlatforms = __getSupportedPlatforms__(str(textBrowser.plainText), template, True)[0]
    clickButton(waitForObject("{text='Choose...' type='QPushButton' unnamed='1' visible='1'}"))
    # don't check because project could exist
    __createProjectSetNameAndPath__(os.path.expanduser("~"), 'untitled', False)
    return displayedPlatforms
