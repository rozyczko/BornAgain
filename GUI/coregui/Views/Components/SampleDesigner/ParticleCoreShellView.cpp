#include "ParticleCoreShellView.h"
#include "ParameterizedItem.h"
#include <QDebug>


ParticleCoreShellView::ParticleCoreShellView(QGraphicsItem *parent)
    : ConnectableView(parent)
{
    setName(Constants::ParticleCoreShellType);
    setLabel("Core shell\nparticle");
    setColor(DesignerHelper::getDefaultParticleColor());
    setRectangle(DesignerHelper::getDefaultBoundingRect(Constants::ParticleCoreShellType));
    addPort("out", NodeEditorPort::OUTPUT, NodeEditorPort::FORM_FACTOR);
    addPort("core", NodeEditorPort::INPUT, NodeEditorPort::FORM_FACTOR);
    addPort("shell", NodeEditorPort::INPUT, NodeEditorPort::FORM_FACTOR);
    m_roundpar = 5;
    m_label_vspace = 45;
}


void ParticleCoreShellView::addView(IView *childView, int /* row */)
{
    int index = childView->getParameterizedItem()->getRegisteredProperty(ParameterizedItem::P_PORT).toInt();
    qDebug() << "ParticleCoreShellView::addView()" << index;
    connectInputPort(dynamic_cast<ConnectableView *>(childView), index);

}
