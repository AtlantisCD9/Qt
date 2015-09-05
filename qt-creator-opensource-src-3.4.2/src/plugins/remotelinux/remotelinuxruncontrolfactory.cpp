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

#include "remotelinuxruncontrolfactory.h"

#include "remotelinuxanalyzesupport.h"
#include "remotelinuxdebugsupport.h"
#include "remotelinuxcustomrunconfiguration.h"
#include "remotelinuxrunconfiguration.h"
#include "remotelinuxruncontrol.h"

#include <debugger/debuggerruncontrol.h>
#include <debugger/debuggerstartparameters.h>
#include <analyzerbase/analyzerstartparameters.h>
#include <analyzerbase/analyzermanager.h>
#include <analyzerbase/analyzerruncontrol.h>
#include <analyzerbase/ianalyzertool.h>
#include <projectexplorer/kitinformation.h>
#include <projectexplorer/target.h>
#include <utils/portlist.h>
#include <utils/qtcassert.h>

using namespace Analyzer;
using namespace Debugger;
using namespace ProjectExplorer;

namespace RemoteLinux {
namespace Internal {

RemoteLinuxRunControlFactory::RemoteLinuxRunControlFactory(QObject *parent)
    : IRunControlFactory(parent)
{
}

RemoteLinuxRunControlFactory::~RemoteLinuxRunControlFactory()
{
}

bool RemoteLinuxRunControlFactory::canRun(RunConfiguration *runConfiguration, RunMode mode) const
{
    if (mode != NormalRunMode && mode != DebugRunMode && mode != DebugRunModeWithBreakOnMain
            && mode != QmlProfilerRunMode) {
        return false;
    }

    const Core::Id id = runConfiguration->id();
    return runConfiguration->isEnabled()
            && (id == RemoteLinuxCustomRunConfiguration::runConfigId()
                || id.name().startsWith(RemoteLinuxRunConfiguration::IdPrefix));
}

RunControl *RemoteLinuxRunControlFactory::create(RunConfiguration *runConfig, RunMode mode,
                                                 QString *errorMessage)
{
    QTC_ASSERT(canRun(runConfig, mode), return 0);

    switch (mode) {
    case NormalRunMode:
        return new RemoteLinuxRunControl(runConfig);
    case DebugRunMode:
    case DebugRunModeWithBreakOnMain: {
        IDevice::ConstPtr dev = DeviceKitInformation::device(runConfig->target()->kit());
        if (!dev) {
            *errorMessage = tr("Cannot debug: Kit has no device.");
            return 0;
        }
        auto * const rc = qobject_cast<AbstractRemoteLinuxRunConfiguration *>(runConfig);
        QTC_ASSERT(rc, return 0);
        if (rc->portsUsedByDebuggers() > dev->freePorts().count()) {
            *errorMessage = tr("Cannot debug: Not enough free ports available.");
            return 0;
        }
        auto *crc = qobject_cast<RemoteLinuxCustomRunConfiguration *>(rc);
        if (crc && crc->localExecutableFilePath().isEmpty()) {
            *errorMessage = tr("Cannot debug: Local executable is not set.");
            return 0;
        }

        DebuggerStartParameters params = LinuxDeviceDebugSupport::startParameters(rc);
        if (mode == DebugRunModeWithBreakOnMain)
            params.breakOnMain = true;
        params.runConfiguration = runConfig;
        DebuggerRunControl * const runControl
                = DebuggerRunControlFactory::doCreate(params, errorMessage);
        if (!runControl)
            return 0;
        LinuxDeviceDebugSupport * const debugSupport =
                new LinuxDeviceDebugSupport(rc, runControl);
        connect(runControl, SIGNAL(finished()), debugSupport, SLOT(handleDebuggingFinished()));
        return runControl;
    }
    case QmlProfilerRunMode: {
        AnalyzerStartParameters params = RemoteLinuxAnalyzeSupport::startParameters(runConfig, mode);
        auto * const rc = qobject_cast<AbstractRemoteLinuxRunConfiguration *>(runConfig);
        QTC_ASSERT(rc, return 0);
        AnalyzerRunControl *runControl = AnalyzerManager::createRunControl(params, runConfig);
        (void) new RemoteLinuxAnalyzeSupport(rc, runControl, mode);
        return runControl;
    }
    case PerfProfilerRunMode:
    case NoRunMode:
    case CallgrindRunMode:
    case MemcheckRunMode:
    case MemcheckWithGdbRunMode:
    case ClangStaticAnalyzerMode:
        QTC_ASSERT(false, return 0);
    }

    QTC_ASSERT(false, return 0);
    return 0;
}

} // namespace Internal
} // namespace RemoteLinux
