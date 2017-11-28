// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/MaterialEditor/MaterialSvc.h
//! @brief     Defines class MaterialSvc
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef MATERIALSVC_H
#define MATERIALSVC_H

#include "MaterialProperty.h"
#include "WinDllMacros.h"
#include <QObject>

class MaterialModel;
class SessionModel;
class MaterialItem;

//! The MaterialEditor is the main class to access materials.
class BA_CORE_API_ MaterialSvc : public QObject
{
    Q_OBJECT
public:
    MaterialSvc();
    virtual ~MaterialSvc();

    static MaterialSvc *instance();

private:
    static MaterialSvc *m_instance;
};



#endif // MATERIALSVC_H


