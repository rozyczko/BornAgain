// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/HardParticle/FormFactorAnisoPyramid.h
//! @brief     Defines class FormFactorAnisoPyramid
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015-16
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FORMFACTORANISOPYRAMID_H
#define FORMFACTORANISOPYRAMID_H

#include "FormFactorPolyhedron.h"

//! @class FormFactorAnisoPyramid
//! @ingroup formfactors
//! @brief The formfactor of a quadratic pyramid
class BA_CORE_API_ FormFactorAnisoPyramid : public FormFactorPolyhedron
{
public:
    FormFactorAnisoPyramid(double length, double width, double height, double alpha);

    FormFactorAnisoPyramid* clone() const final {
        return new FormFactorAnisoPyramid(m_length, m_width, m_height, m_alpha); }
    void accept(ISampleVisitor *visitor) const final { visitor->visit(this); }

    double getLength() const { return m_length; }
    double getWidth()  const { return m_width; }
    double getHeight() const { return m_height; }
    double getAlpha()  const { return m_alpha; }

private:
    static const PolyhedralTopology topology;
    void onChange() final;

    double m_length;
    double m_width;
    double m_height;
    double m_alpha;
};

#endif // FORMFACTORANISOPYRAMID_H