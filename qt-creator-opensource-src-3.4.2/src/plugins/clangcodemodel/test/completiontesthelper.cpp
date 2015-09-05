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

#ifdef WITH_TESTS

#include "completiontesthelper.h"
#include "../clangcompletion.h"
#include "../clangcompleter.h"
#include "../clangcodemodelplugin.h"

#include <cpptools/cppcompletionassist.h>

#include <texteditor/textdocument.h>
#include <texteditor/texteditor.h>
#include <texteditor/codeassist/iassistproposal.h>
#include <texteditor/codeassist/genericproposalmodel.h>

#include <utils/fileutils.h>
#include <utils/changeset.h>

#include <QDir>
#include <QtTest>

using namespace ClangCodeModel;
using namespace ClangCodeModel::Internal;
using namespace TextEditor;
using namespace CPlusPlus;
using namespace CppTools::Internal;

namespace ClangCodeModel {
namespace Internal {

CompletionTestHelper::CompletionTestHelper(QObject *parent) :
    QObject(parent),
    m_completer(new ClangCompleter()),
    m_position(0),
    m_line(0),
    m_column(0)
{
    m_clangOptions << QLatin1String("-std=c++0x")
                   << QLatin1String("-ObjC++");
}

CompletionTestHelper::~CompletionTestHelper()
{
}

void CompletionTestHelper::operator <<(const QString &fileName)
{
    QResource res(QLatin1String(":/unittests/ClangCodeModel/") + fileName);
    m_sourceCode = QByteArray(reinterpret_cast<const char*>(res.data()), res.size());
    findCompletionPos();

    QString path = QDir::tempPath() + QLatin1String("/file.h");
    ::Utils::FileSaver srcSaver(path);
    srcSaver.write(m_sourceCode);
    srcSaver.finalize();

    m_completer->setFileName(path);
    m_completer->setOptions(m_clangOptions);
}

QStringList CompletionTestHelper::codeCompleteTexts()
{
    QList<CodeCompletionResult> results =
            m_completer->codeCompleteAt(m_line, m_column, m_unsavedFiles);

    QStringList completions;
    foreach (const CodeCompletionResult& ccr, results)
         completions << ccr.text();
    return completions;
}

QList<CodeCompletionResult> CompletionTestHelper::codeComplete()
{
    return m_completer->codeCompleteAt(m_line, m_column, m_unsavedFiles);
}

int CompletionTestHelper::position() const
{
    return m_position;
}

const QByteArray &CompletionTestHelper::source() const
{
    return m_sourceCode;
}

void CompletionTestHelper::addOption(const QString &option)
{
    m_clangOptions << option;
}

void CompletionTestHelper::findCompletionPos()
{
    m_position = m_sourceCode.indexOf("<<<<");
    QVERIFY(m_position != -1);
    m_sourceCode[m_position] = ' ';
    m_sourceCode[m_position + 1] = ' ';
    m_sourceCode[m_position + 2] = ' ';
    m_sourceCode[m_position + 3] = ' ';

    // substring from 0 to '@' position
    QByteArray substr(m_sourceCode.data(), m_position);

    m_line = 1;
    m_column = 1;
    for (int i = 0; i < substr.size(); ++i) {
        if (substr[i] == '\n') {
            ++m_line;
            m_column = 1;
        } else {
            ++m_column;
        }
    }
}

} // namespace Internal
} // namespace ClangCodeModel

#endif
