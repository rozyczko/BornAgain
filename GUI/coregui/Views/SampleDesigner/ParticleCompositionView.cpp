// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/SampleDesigner/ParticleCompositionView.cpp
//! @brief     Implements class ParticleCompositionView
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "ParticleCompositionView.h"
#include "ParticleItem.h"
#include "SessionItem.h"

ParticleCompositionView::ParticleCompositionView(QGraphicsItem *parent) : ConnectableView(parent)
{
    setName(Constants::ParticleCompositionType);
    setColor(DesignerHelper::getDefaultParticleColor());
    setRectangle(DesignerHelper::getDefaultBoundingRect(Constants::ParticleCoreShellType));
    addPort("out", NodeEditorPort::OUTPUT, NodeEditorPort::FORM_FACTOR)
        ->setToolTip(QStringLiteral("Connect to the ParticleLayout"));
    addPort("particles", NodeEditorPort::INPUT, NodeEditorPort::FORM_FACTOR)
        ->setToolTip(QStringLiteral("Connect particles"));
    addPort("transformation", NodeEditorPort::INPUT, NodeEditorPort::TRANSFORMATION)
        ->setToolTip(QStringLiteral("Connect rotation to this port, if necessary"));
    m_roundpar = 5;
    m_label_vspace = 45;
}

void ParticleCompositionView::addView(IView *childView, int /* row */)
{
    int index = 0;
    if (this->getItem()->tagFromItem(childView->getItem()) == ParticleItem::T_TRANSFORMATION)
        index = 1;
    connectInputPort(dynamic_cast<ConnectableView *>(childView), index);
}
