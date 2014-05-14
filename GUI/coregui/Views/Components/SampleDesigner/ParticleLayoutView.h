#ifndef PARTICLELAYOUTVIEW_H
#define PARTICLELAYOUTVIEW_H

#include "ConnectableView.h"

class ParticleLayoutView : public ConnectableView
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName )

public:
    enum { Type = DesignerHelper::ParticleLayoutType };

    ParticleLayoutView(QGraphicsItem *parent = 0);

    int type() const { return Type; }

    void addView(IView *childView, int row = 0); // to add Particle
};


#endif // PARTICLELAYOUTVIEW_H
