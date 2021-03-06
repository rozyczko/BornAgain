// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/SampleDesigner/ParticleView.h
//! @brief     Defines class ParticleView
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef PARTICLEVIEW_H
#define PARTICLEVIEW_H

#include "ConnectableView.h"
#include <QPixmap>

//! Class representing view of Particle item
class BA_CORE_API_ ParticleView : public ConnectableView
{
    Q_OBJECT

public:
    enum { TYPE = DesignerHelper::PARTICLE };

    ParticleView(QGraphicsItem *parent = 0);

    int type() const { return TYPE; }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void onPropertyChange(const QString &propertyName);

    void addView(IView *childView, int row = 0); // to add Transformation

protected:
    void update_appearance();

private:
    void updatePixmap();
    void updateToolTip();

    QPixmap m_pixmap;
};



#endif // PARTICLEVIEW_H
