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

#include "stackframe.h"

#include <QFileInfo>
#include <QDebug>
#include <QDir>
#include <QTextStream>
#include <QCoreApplication>

namespace Debugger {
namespace Internal {

////////////////////////////////////////////////////////////////////////
//
// StackFrame
//
////////////////////////////////////////////////////////////////////////

StackFrame::StackFrame()
  : level(-1), line(-1), address(0), usable(false)
{}

void StackFrame::clear()
{
    line = level = -1;
    function.clear();
    file.clear();
    from.clear();
    to.clear();
    address = 0;
}

bool StackFrame::isUsable() const
{
    return usable;
}

QString StackFrame::toString() const
{
    QString res;
    QTextStream str(&res);
    str << tr("Address:") << ' ';
    str.setIntegerBase(16);
    str << address;
    str.setIntegerBase(10);
    str << ' '
        << tr("Function:") << ' ' << function << ' '
        << tr("File:") << ' ' << file << ' '
        << tr("Line:") << ' ' << line << ' '
        << tr("From:") << ' ' << from << ' '
        << tr("To:") << ' ' << to;
    return res;
}

QString StackFrame::toToolTip() const
{
    const QString filePath = QDir::toNativeSeparators(file);
    QString res;
    QTextStream str(&res);
    str << "<html><body><table>";
    if (address) {
        str << "<tr><td>" << tr("Address:") << "</td><td>0x";
        str.setIntegerBase(16);
        str <<  address;
    }
    str.setIntegerBase(10);
    str << "</td></tr>";
    if (!function.isEmpty())
        str << "<tr><td>" << tr("Function:") << "</td><td>" << function << "</td></tr>";
    if (!file.isEmpty())
        str << "<tr><td>" << tr("File:") << "</td><td>" << filePath << "</td></tr>";
    if (line != -1)
        str << "<tr><td>" << tr("Line:") << "</td><td>" << line << "</td></tr>";
    if (!from.isEmpty())
        str << "<tr><td>" << tr("From:") << "</td><td>" << from << "</td></tr>";
    if (!to.isEmpty())
        str << "<tr><td>" << tr("To:") << "</td><td>" << to << "</td></tr>";
    str << "</table></body></html>";
    return res;
}

QDebug operator<<(QDebug d, const  StackFrame &f)
{
    QString res;
    QTextStream str(&res);
    str << "level=" << f.level << " address=" << f.address;
    if (!f.function.isEmpty())
        str << ' ' << f.function;
    if (!f.file.isEmpty())
        str << ' ' << f.file << ':' << f.line;
    if (!f.from.isEmpty())
        str << " from=" << f.from;
    if (!f.to.isEmpty())
        str << " to=" << f.to;
    d.nospace() << res;
    return d;
}

} // namespace Internal
} // namespace Debugger