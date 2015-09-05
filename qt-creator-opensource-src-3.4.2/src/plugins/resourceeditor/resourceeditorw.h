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

#ifndef RESOURCEEDITORW_H
#define RESOURCEEDITORW_H

#include <coreplugin/idocument.h>
#include <coreplugin/editormanager/ieditor.h>

QT_BEGIN_NAMESPACE
class QMenu;
class QToolBar;
QT_END_NAMESPACE

namespace ResourceEditor {
namespace Internal {

class ResourceEditorPlugin;
class ResourceEditorW;
class QrcEditor;

class ResourceEditorDocument
  : public Core::IDocument
{
    Q_OBJECT
    Q_PROPERTY(QString plainText READ plainText STORED false) // For access by code pasters

public:
    ResourceEditorDocument(ResourceEditorW *parent = 0);

    //IDocument
    bool save(QString *errorString, const QString &fileName, bool autoSave);
    QString plainText() const;
    bool setContents(const QByteArray &contents);
    bool shouldAutoSave() const;
    bool isModified() const;
    bool isSaveAsAllowed() const;
    bool reload(QString *errorString, ReloadFlag flag, ChangeType type);
    QString defaultPath() const;
    QString suggestedFileName() const;
    void setFilePath(const Utils::FileName &newName);
    void setBlockDirtyChanged(bool value);

public slots:
    void dirtyChanged(bool);

private:
    bool m_blockDirtyChanged;
    ResourceEditorW *m_parent;
};

class ResourceEditorW : public Core::IEditor
{
    Q_OBJECT

public:
    ResourceEditorW(const Core::Context &context,
                   ResourceEditorPlugin *plugin,
                   QWidget *parent = 0);
    ~ResourceEditorW();

    // IEditor
    bool open(QString *errorString, const QString &fileName, const QString &realFileName);
    Core::IDocument *document() { return m_resourceDocument; }
    QWidget *toolBar();

    void setSuggestedFileName(const QString &fileName);

private slots:
    void onUndoStackChanged(bool canUndo, bool canRedo);
    void setShouldAutoSave(bool sad = true) { m_shouldAutoSave = sad; }
    void showContextMenu(const QPoint &globalPoint, const QString &fileName);
    void openCurrentFile();
    void openFile(const QString &fileName);
    void renameCurrentFile();
    void copyCurrentResourcePath();

private:
    const QString m_extension;
    const QString m_fileFilter;
    QString m_displayName;
    QString m_suggestedName;
    QrcEditor *m_resourceEditor;
    ResourceEditorDocument *m_resourceDocument;
    ResourceEditorPlugin *m_plugin;
    bool m_shouldAutoSave;
    QMenu *m_contextMenu;
    QMenu *m_openWithMenu;
    QString m_currentFileName;
    QToolBar *m_toolBar;
    QAction *m_renameAction;
    QAction *m_copyFileNameAction;

public slots:
    void onRefresh();

public:
    void onUndo();
    void onRedo();

    friend class ResourceEditorDocument;
};

} // namespace Internal
} // namespace ResourceEditor

#endif // RESOURCEEDITORW_H
