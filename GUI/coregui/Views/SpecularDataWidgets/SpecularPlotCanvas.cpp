// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/SpecularDataWidgets/SpecularPlotCanvas.cpp
//! @brief     Declares class SpecularPlotCanvas
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "SpecularPlotCanvas.h"
#include "SpecularPlot.h"
#include "SpecularDataItem.h"
#include <QVBoxLayout>

SpecularPlotCanvas::SpecularPlotCanvas(QWidget *parent)
    : SessionItemWidget(parent)
    , m_plot(new SpecularPlot)
{
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);

    layout->addWidget(m_plot);

    setLayout(layout);
}

void SpecularPlotCanvas::setItem(SessionItem* specularDataItem)
{
    SessionItemWidget::setItem(specularDataItem);
    m_plot->setItem(dynamic_cast<SpecularDataItem*>(specularDataItem));
}

SpecularPlot* SpecularPlotCanvas::specularPlot()
{
    return m_plot;
}

QCustomPlot* SpecularPlotCanvas::customPlot()
{
    return m_plot->customPlot();
}