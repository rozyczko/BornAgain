// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/SampleDesigner/ParticleCompositionView.h
//! @brief     Defines class ParticleCompositionView
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef PARTICLECOMPOSITIONVIEW_H
#define PARTICLECOMPOSITIONVIEW_H

#include "ConnectableView.h"

//! Class representing view of Particle item
class BA_CORE_API_ ParticleCompositionView : public ConnectableView
{
    Q_OBJECT

public:
    enum { TYPE = DesignerHelper::PARTICLE };

    ParticleCompositionView(QGraphicsItem *parent = 0);

    int type() const { return TYPE; }

    void addView(IView *childView, int row = 0);

};


#endif // PARTICLECOMPOSITIONVIEW_H

