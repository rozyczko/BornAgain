// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/RefractiveIndexItem.h
//! @brief     Defines class RefractiveIndexItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef REFRACTIVEINDEXITEM_H
#define REFRACTIVEINDEXITEM_H


#include "ParameterizedItem.h"

class BA_CORE_API_ RefractiveIndexItem : public ParameterizedItem
{
    Q_OBJECT
public:
    static const QString P_DELTA;
    static const QString P_BETA;
    explicit RefractiveIndexItem(ParameterizedItem *parent=0);
    ~RefractiveIndexItem(){}
    QString getItemLabel() const;

    double getDelta() const;
    void setDelta(double delta);

    double getBeta() const;
    void setBeta(double beta);
};



#endif
