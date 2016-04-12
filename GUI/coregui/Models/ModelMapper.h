// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/ModelMapper.h
//! @brief     Defines class ModelMapper
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef MODELMAPPER_H
#define MODELMAPPER_H

#include "WinDllMacros.h"

#include <QObject>
#include <QVector>
#include <functional>

class QModelIndex;
class SessionModel;
class SessionItem;


class BA_CORE_API_ ModelMapper : public QObject
{
    Q_OBJECT
public:
    ModelMapper(QObject *parent = 0);

    void setItem(SessionItem* item);

    void setOnValueChange(std::function<void(void)> f);

    void setOnPropertyChange(std::function<void(QString)> f);

    void setOnChildPropertyChange(std::function<void(SessionItem*,QString)> f);

    void setOnParentChange(std::function<void(SessionItem*)> f);

    void setOnChildrenChange(std::function<void(SessionItem*)> f);

    void setOnSiblingsChange(std::function<void(void)> f);

    void setOnAnyChildChange(std::function<void(SessionItem*)> f);

    void setActive(bool state) {m_active = state;}

public slots:
    void onDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight,
                       const QVector<int> & roles = QVector<int> ());

    void onRowsInserted(const QModelIndex & parent, int first, int last);

    void onBeginRemoveRows(const QModelIndex & parent, int first, int last);

    void onRowRemoved(const QModelIndex & parent, int first, int last);

private:
    void setModel(SessionModel *model);
    int nestlingDepth(SessionItem* item, int level = 0);

    void callOnValueChange();
    void callOnPropertyChange(const QString &name);
    void callOnChildPropertyChange(SessionItem *item, const QString &name);
    void callOnParentChange(SessionItem *new_parent);
    void callOnChildrenChange(SessionItem *item);
    void callOnSiblingsChange();
    void callOnAnyChildChange(SessionItem *item);


    bool m_active;
    SessionModel *m_model;
    SessionItem *m_item;
    std::vector<std::function<void(void)>> m_onValueChange;
    std::vector<std::function<void(QString)>> m_onPropertyChange;
    std::vector<std::function<void(SessionItem*,QString)>> m_onChildPropertyChange;
    std::vector<std::function<void(SessionItem*)>> m_onParentChange;
    std::vector<std::function<void(SessionItem*)>> m_onChildrenChange;
    std::vector<std::function<void(void)>> m_onSiblingsChange;
    std::vector<std::function<void(SessionItem*)>> m_onAnyChildChange;
};

#endif