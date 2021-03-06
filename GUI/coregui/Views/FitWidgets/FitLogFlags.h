// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/FitWidgets/FitLogFlags.h
//! @brief     Defines class FitSuiteManager
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef FITLOGFLAGS_H
#define FITLOGFLAGS_H

#include "WinDllMacros.h"
#include <QFlags>
#include <QColor>

//! Flags for log records related to fitting.

class BA_CORE_API_ FitLogFlags
{
public:
    enum EMessageType {
        DEFAULT,
        SUCCESS,
        HIGHLIGHT,
        WARNING,
        ERROR
    };
    Q_DECLARE_FLAGS(MessageType, EMessageType)

    static Qt::GlobalColor color(MessageType messageType);
};

Q_DECLARE_OPERATORS_FOR_FLAGS(FitLogFlags::MessageType)

#endif //  PROJECTFLAGS_H
