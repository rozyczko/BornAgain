// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/PropertyEditor/PropertyWidgetItem.cpp
//! @brief     Implements class PropertyWidgetItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "PropertyWidgetItem.h"
#include "SessionItem.h"
#include "SessionModel.h"
#include "SessionItemUtils.h"
#include "SessionModelDelegate.h"
#include "CustomEditors.h"
#include <QLabel>
#include <QWidget>
#include <QDataWidgetMapper>
#include <QGridLayout>
#include <QComboBox>
#include <QDebug>
#include <QSpinBox>
#include <QDoubleSpinBox>

PropertyWidgetItem::PropertyWidgetItem(QWidget* parent)
    : QObject(parent)
    , m_label(new QLabel)
    , m_editor(nullptr)
    , m_dataMapper(new QDataWidgetMapper(this))
    , m_delegate(new SessionModelDelegate(nullptr))
    , m_item(nullptr)
{
    m_label->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed));
}

PropertyWidgetItem::~PropertyWidgetItem()
{
    m_editor->clearFocus();
    delete m_label;
    delete m_editor;
    delete m_delegate;
}

void PropertyWidgetItem::setItemEditor(const SessionItem* item, QWidget* editor)
{
    Q_ASSERT(m_item == nullptr);
    m_item = item;
    m_editor = editor;

    m_label->setText(item->displayName());

    m_editor->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));

    m_dataMapper->setModel(item->model());
    m_dataMapper->setRootIndex(item->parent()->index());
    m_dataMapper->setCurrentModelIndex(item->index());
    m_dataMapper->addMapping(m_label, 0);
    m_dataMapper->addMapping(m_editor, 1);
    m_dataMapper->setItemDelegate(m_delegate);

    QModelIndex valueIndex = item->index().sibling(item->index().row(), 1);
    if (valueIndex.isValid())
        m_delegate->setEditorData(editor, valueIndex);

    connectEditor(editor);

    updateItemRoles();
}

void PropertyWidgetItem::addToGrid(QGridLayout* gridLayout, int nrow)
{
    Q_ASSERT(m_label);
    Q_ASSERT(m_editor);

    gridLayout->addWidget(m_label, nrow, 0);
    gridLayout->addWidget(m_editor, nrow, 1);
}

void PropertyWidgetItem::updateItemRoles()
{
    Q_ASSERT(m_item);
    m_label->setEnabled(m_item->isEnabled());
    m_editor->setEnabled(m_item->isEnabled());
    m_label->setToolTip(SessionItemUtils::ToolTipRole(*m_item).toString());
    m_editor->setToolTip(SessionItemUtils::ToolTipRole(*m_item).toString());
}

const SessionItem* PropertyWidgetItem::item()
{
    return m_item;
}

//! Provide additional connections of editor to model mapper.

void PropertyWidgetItem::connectEditor(QWidget* editor)
{
    if (auto customEditor = dynamic_cast<CustomEditor*>(editor)) {
        connect(customEditor, &CustomEditor::dataChanged,
                m_delegate, &SessionModelDelegate::onCustomEditorDataChanged);
    }
}
