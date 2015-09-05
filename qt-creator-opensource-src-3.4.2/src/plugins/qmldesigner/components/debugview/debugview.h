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

#ifndef DEBUGVIEW_H
#define DEBUGVIEW_H

#include <abstractview.h>
#include <QPointer>

namespace QmlDesigner {

namespace Internal {

class DebugViewWidget;

class  DebugView : public AbstractView
{
    Q_OBJECT

public:
    DebugView(QObject *parent = 0);
    ~DebugView();

    // AbstractView
    void modelAttached(Model *model) Q_DECL_OVERRIDE;
    void modelAboutToBeDetached(Model *model) Q_DECL_OVERRIDE;

    void importsChanged(const QList<Import> &addedImports, const QList<Import> &removedImports) Q_DECL_OVERRIDE;

    void nodeCreated(const ModelNode &createdNode) Q_DECL_OVERRIDE;
    void nodeAboutToBeRemoved(const ModelNode &removedNode) Q_DECL_OVERRIDE;
    void nodeReparented(const ModelNode &node, const NodeAbstractProperty &newPropertyParent,
                        const NodeAbstractProperty &oldPropertyParent, AbstractView::PropertyChangeFlags propertyChange) Q_DECL_OVERRIDE;
    void nodeIdChanged(const ModelNode& node, const QString& newId, const QString& oldId) Q_DECL_OVERRIDE;
    void propertiesAboutToBeRemoved(const QList<AbstractProperty>& propertyList) Q_DECL_OVERRIDE;
    void variantPropertiesChanged(const QList<VariantProperty>& propertyList, PropertyChangeFlags propertyChange) Q_DECL_OVERRIDE;
    void bindingPropertiesChanged(const QList<BindingProperty>& propertyList, PropertyChangeFlags propertyChange) Q_DECL_OVERRIDE;
    void signalHandlerPropertiesChanged(const QVector<SignalHandlerProperty>& propertyList, PropertyChangeFlags propertyChange) Q_DECL_OVERRIDE;
    void rootNodeTypeChanged(const QString &type, int majorVersion, int minorVersion) Q_DECL_OVERRIDE;

    void selectedNodesChanged(const QList<ModelNode> &selectedNodeList,
                              const QList<ModelNode> &lastSelectedNodeList) Q_DECL_OVERRIDE;
    void scriptFunctionsChanged(const ModelNode &node, const QStringList &scriptFunctionList) Q_DECL_OVERRIDE;
    void propertiesRemoved(const QList<AbstractProperty> &propertyList) Q_DECL_OVERRIDE;

    void auxiliaryDataChanged(const ModelNode &node, const PropertyName &name, const QVariant &data) Q_DECL_OVERRIDE;

    void rewriterBeginTransaction() Q_DECL_OVERRIDE;
    void rewriterEndTransaction() Q_DECL_OVERRIDE;

    WidgetInfo widgetInfo() Q_DECL_OVERRIDE;
    bool hasWidget() const Q_DECL_OVERRIDE;

    void instancePropertyChange(const QList<QPair<ModelNode, PropertyName> > &propertyList) Q_DECL_OVERRIDE;
    void instancesCompleted(const QVector<ModelNode> &completedNodeList) Q_DECL_OVERRIDE;
    void instanceInformationsChange(const QMultiHash<ModelNode, InformationName> &informationChangeHash) Q_DECL_OVERRIDE;
    void instancesRenderImageChanged(const QVector<ModelNode> &nodeList) Q_DECL_OVERRIDE;
    void instancesPreviewImageChanged(const QVector<ModelNode> &nodeList) Q_DECL_OVERRIDE;
    void instancesChildrenChanged(const QVector<ModelNode> &nodeList) Q_DECL_OVERRIDE;
    void customNotification(const AbstractView *view, const QString &identifier, const QList<ModelNode> &nodeList, const QList<QVariant> &data) Q_DECL_OVERRIDE;

    void nodeSourceChanged(const ModelNode &modelNode, const QString &newNodeSource) Q_DECL_OVERRIDE;

    void nodeRemoved(const ModelNode &removedNode, const NodeAbstractProperty &parentProperty, PropertyChangeFlags propertyChange) Q_DECL_OVERRIDE;
    void nodeAboutToBeReparented(const ModelNode &node, const NodeAbstractProperty &newPropertyParent, const NodeAbstractProperty &oldPropertyParent, PropertyChangeFlags propertyChange) Q_DECL_OVERRIDE;
    void instancesToken(const QString &tokenName, int tokenNumber, const QVector<ModelNode> &nodeVector) Q_DECL_OVERRIDE;
    void currentStateChanged(const ModelNode &node) Q_DECL_OVERRIDE;
    void nodeOrderChanged(const NodeListProperty &listProperty, const ModelNode &movedNode, int oldIndex) Q_DECL_OVERRIDE;

protected:
    void log(const QString &title, const QString &message, bool highlight = false);
    void logInstance(const QString &title, const QString &message, bool highlight = false);

private: //variables
    QPointer<DebugViewWidget> m_debugViewWidget;
};

} // namespace Internal

} // namespace QmlDesigner

#endif // DEBUGVIEW_H
