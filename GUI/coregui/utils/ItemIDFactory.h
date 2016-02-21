// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Util/ItemIDFactory.h
//! @brief     Defines class ItemIDFactory
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //
#ifndef ItemIDFactory_H
#define ItemIDFactory_H

#include <QUuid>
#include <QMap>

class ParameterizedItem;

class ItemIDFactory {
public:
    // delete copy/move constructor/assignment:
    ItemIDFactory(const ItemIDFactory&) = delete;
    ItemIDFactory(ItemIDFactory&&) = delete;
    ItemIDFactory& operator=(const ItemIDFactory&) = delete;
    ItemIDFactory& operator=(ItemIDFactory&&) = delete;

    static ItemIDFactory& instance();

    static QString createID(ParameterizedItem* toBeInsertedItem);

    static QString getID(ParameterizedItem* existingItem);

    static ParameterizedItem* getItem(QString existingID);

    static int IDSize();

private:
    ItemIDFactory() = default;

    QMap<QString, ParameterizedItem*> IDtoItemMap;
    QMap<ParameterizedItem*, QString> ItemtoIDMap;
};

#endif