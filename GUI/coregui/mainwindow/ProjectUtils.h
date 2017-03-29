// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/mainwindow/ProjectUtils.h
//! @brief     Defines ProjectUtils namespace
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2017
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   J. Burle, J. M. Fisher, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef PROJECTUTILS_H
#define PROJECTUTILS_H

#include "WinDllMacros.h"
#include <QString>

//! Defines convenience function for project manager and document.

namespace ProjectUtils
{

//! Returns project name deduced from project file name.
BA_CORE_API_ QString projectName(const QString& projectFileName);

//! Returns project directory deduced from project file name.
BA_CORE_API_ QString projectDir(const QString& projectFileName);

//! Returns fixed name for autosave sub-directory.
BA_CORE_API_ QString autosaveSubdir();

//! Returns name of autosave directory for project with given project file name.
BA_CORE_API_ QString autosaveDir(const QString& projectFileName);

//! Returns name of project for autoSave from given project file name.
BA_CORE_API_ QString autosaveName(const QString& projectFileName);

//! Returns true if project with given projectFileName contains autosaved data.
BA_CORE_API_ bool hasAutosavedData(const QString& projectFileName);

}

#endif // PROJECTUTILS_H
