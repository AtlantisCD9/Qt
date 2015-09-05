/**************************************************************************
**
** Copyright (C) 2012 - 2014 BlackBerry Limited. All rights reserved.
**
** Contact: BlackBerry (qt@blackberry.com)
** Contact: KDAB (info@kdab.com)
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

#include "qnxqtversion.h"

#include "qnxconstants.h"

#include "qnxutils.h"

#include <coreplugin/featureprovider.h>
#include <utils/hostosinfo.h>

#include <qtsupport/qtsupportconstants.h>

using namespace Qnx;
using namespace Qnx::Internal;

QnxQtVersion::QnxQtVersion()
    : QnxAbstractQtVersion()
{
}

QnxQtVersion::QnxQtVersion(QnxArchitecture arch, const Utils::FileName &path, bool isAutoDetected, const QString &autoDetectionSource)
    : QnxAbstractQtVersion(arch, path, isAutoDetected, autoDetectionSource)
{
    setUnexpandedDisplayName(defaultUnexpandedDisplayName(path, false));
}

QnxQtVersion *QnxQtVersion::clone() const
{
    return new QnxQtVersion(*this);
}

QnxQtVersion::~QnxQtVersion()
{
}

QString QnxQtVersion::type() const
{
    return QLatin1String(Constants::QNX_QNX_QT);
}

QString QnxQtVersion::description() const
{
    //: Qt Version is meant for QNX
    return tr("QNX %1").arg(archString());
}

Core::FeatureSet QnxQtVersion::availableFeatures() const
{
    Core::FeatureSet features = QnxAbstractQtVersion::availableFeatures();
    features |= Core::FeatureSet(Constants::QNX_QNX_FEATURE);
    features.remove(Core::Feature(QtSupport::Constants::FEATURE_QT_CONSOLE));
    features.remove(Core::Feature(QtSupport::Constants::FEATURE_QT_WEBKIT));
    return features;
}

QString QnxQtVersion::platformName() const
{
    return QString::fromLatin1(Constants::QNX_QNX_PLATFORM_NAME);
}

QString QnxQtVersion::platformDisplayName() const
{
    return tr("QNX");
}

QString QnxQtVersion::sdkDescription() const
{
    return tr("QNX Software Development Platform:");
}

QList<Utils::EnvironmentItem> QnxQtVersion::environment() const
{
    return QnxUtils::qnxEnvironment(sdkPath());
}
