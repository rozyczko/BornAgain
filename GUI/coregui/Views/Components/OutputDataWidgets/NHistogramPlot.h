// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/Components/OutputDataWidgets/NHistogramPlot.h
//! @brief     Defines class NHistogramPlot
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef NHISTOGRAMPLOT_H
#define NHISTOGRAMPLOT_H

#include "WinDllMacros.h"
#include <QWidget>


class BA_CORE_API_ NHistogramPlot : public QWidget
{
    Q_OBJECT
public:
    explicit NHistogramPlot(QWidget *parent = 0);

    QSize sizeHint() const { return QSize(128, 128); }
    QSize minimumSizeHint() const { return QSize(64, 64); }

public slots:

private:

};




#endif
