// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/InstrumentWidgets/OffSpecInstrumentEditor.h
//! @brief     Defines class OffSpecInstrumentEditor
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef OFFSPECINSTRUMENTEDITOR_H
#define OFFSPECINSTRUMENTEDITOR_H

#include "SessionItemWidget.h"

class OffSpecInstrumentItem;
class OffSpecBeamEditor;
class GISASDetectorEditor;
class EnvironmentEditor;
class PolarizationAnalysisEditor;
class ColumnResizer;

class BA_CORE_API_ OffSpecInstrumentEditor : public SessionItemWidget
{
    Q_OBJECT

public:
    OffSpecInstrumentEditor(QWidget* parent = nullptr);

protected:
    void subscribeToItem();

private:
    OffSpecInstrumentItem* instrumentItem();
    ColumnResizer* m_columnResizer;
    OffSpecBeamEditor* m_beamEditor;
    GISASDetectorEditor* m_detectorEditor;
    EnvironmentEditor* m_environmentEditor;
    PolarizationAnalysisEditor* m_polarizationAnalysisEditor;
};

#endif  // OFFSPECINSTRUMENTEDITOR_H
