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

#include "textdocument.h"
#include "editormanager.h"

#include <QDebug>
#include <QTextCodec>

/*!
    \class Core::TextFile
    \brief Base class for text files with encoding helpers.

    Stores the format obtained from read operations and uses that when writing
    out files, thus ensuring that CRLF/encodings are preserved.

    \sa Utils::TextFileUtils
*/

enum { debug = 0 };

namespace Core {

namespace Internal {
class TextDocumentPrivate
{
public:
    TextDocumentPrivate() : m_readResult(Utils::TextFileFormat::ReadSuccess) {}

    Utils::TextFileFormat m_format;
    Utils::TextFileFormat::ReadResult m_readResult;
    QByteArray m_decodingErrorSample;
};

} // namespace Internal

TextDocument::TextDocument(QObject *parent) :
    IDocument(parent), d(new Internal::TextDocumentPrivate)
{
    setCodec(Core::EditorManager::instance()->defaultTextCodec());
}

TextDocument::~TextDocument()
{
    delete d;
}

bool TextDocument::hasDecodingError() const
{
    return d->m_readResult == Utils::TextFileFormat::ReadEncodingError;
}

QByteArray TextDocument::decodingErrorSample() const
{
    return d->m_decodingErrorSample;
}

/*!
    \brief Writes out text using the format obtained from the last read.
*/

bool TextDocument::write(const QString &fileName, const QString &data, QString *errorMessage) const
{
    return write(fileName, format(), data, errorMessage);
}

/*!
    \brief Writes out text using a custom format obtained.
*/

bool TextDocument::write(const QString &fileName, const Utils::TextFileFormat &format, const QString &data, QString *errorMessage) const
{
    if (debug)
        qDebug() << Q_FUNC_INFO << this << fileName;
    return format.writeFile(fileName, data, errorMessage);
}

/*!
    \brief Autodetect format and read in a text file.
*/

TextDocument::ReadResult TextDocument::read(const QString &fileName, QStringList *plainTextList, QString *errorString)
{
    d->m_readResult =
        Utils::TextFileFormat::readFile(fileName, codec(),
                                        plainTextList, &d->m_format, errorString, &d->m_decodingErrorSample);
    return d->m_readResult;
}

/*!
    \brief Autodetect format and read in a text file.
*/

TextDocument::ReadResult TextDocument::read(const QString &fileName, QString *plainText, QString *errorString)
{
    d->m_readResult =
        Utils::TextFileFormat::readFile(fileName, codec(),
                                        plainText, &d->m_format, errorString, &d->m_decodingErrorSample);
    return d->m_readResult;
}

const QTextCodec *TextDocument::codec() const
{
    return d->m_format.codec;
}

void TextDocument::setCodec(const QTextCodec *codec)
{
    if (debug)
        qDebug() << Q_FUNC_INFO << this << (codec ? codec->name() : QByteArray());
    d->m_format.codec = codec;
}

/*!
    \brief Returns the format obtained from the last call to read().
*/

Utils::TextFileFormat TextDocument::format() const
{
    return d->m_format;
}

} // namespace Core
