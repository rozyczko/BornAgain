// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Rotation/Rotations.cpp
//! @brief     Implements IRotation classes.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Rotations.h"
#include "BornAgainNamespace.h"
#include "ISampleVisitor.h"

IRotation* IRotation::createRotation(const Geometry::Transform3D& transform)
{
    double alpha, beta, gamma;
    transform.calculateEulerAngles(&alpha, &beta, &gamma);
    Geometry::Transform3D::ERotationType rot_type = transform.getRotationType();
    switch (rot_type) {
    case Geometry::Transform3D::XAXIS:
        if (alpha>0.0) beta = -beta;
        return new RotationX(beta);
    case Geometry::Transform3D::YAXIS:
        if (alpha>0.0 && alpha<3.14) beta = -beta;
        return new RotationY(beta);
    case Geometry::Transform3D::ZAXIS:
        return new RotationZ(alpha);
    default:
        return new RotationEuler(alpha, beta, gamma);
    }
}

bool IRotation::isIdentity() const
{
    return getTransform3D().isIdentity();
}

//! Returns concatenated rotation (first right, then left).

IRotation* CreateProduct(const IRotation& left, const IRotation& right)
{
    Geometry::Transform3D tr_left = left.getTransform3D();
    Geometry::Transform3D tr_right = right.getTransform3D();
    IRotation *p_result = IRotation::createRotation(tr_left*tr_right);
    return p_result;
}

// --- RotationX --------------------------------------------------------------

RotationX::RotationX(double angle)
    : m_angle(angle)
{
    setName(BornAgain::XRotationType);
    registerUnlimitedAngle(BornAgain::Angle, &m_angle);
}

Geometry::Transform3D RotationX::getTransform3D() const
{
    return Geometry::Transform3D::createRotateX(m_angle);
}

// --- RotationY --------------------------------------------------------------

RotationY::RotationY(double angle)
    : m_angle(angle)
{
    setName(BornAgain::YRotationType);
    registerUnlimitedAngle(BornAgain::Angle, &m_angle);
}

Geometry::Transform3D RotationY::getTransform3D() const
{
    return Geometry::Transform3D::createRotateY(m_angle);
}

// --- RotationZ --------------------------------------------------------------

RotationZ::RotationZ(double angle)
    : m_angle(angle)
{
    setName(BornAgain::ZRotationType);
    registerUnlimitedAngle(BornAgain::Angle, &m_angle);
}

Geometry::Transform3D RotationZ::getTransform3D() const
{
    return Geometry::Transform3D::createRotateZ(m_angle);
}

// --- RotationEuler ----------------------------------------------------------

RotationEuler::RotationEuler(double alpha, double beta, double gamma)
    : m_alpha(alpha), m_beta(beta), m_gamma(gamma)
{
    setName(BornAgain::EulerRotationType);
    registerUnlimitedAngle(BornAgain::Alpha, &m_alpha);
    registerUnlimitedAngle(BornAgain::Beta, &m_beta);
    registerUnlimitedAngle(BornAgain::Gamma, &m_gamma);
}

IRotation* RotationEuler::createInverse() const
{
    Geometry::Transform3D inverse_transform(getTransform3D().getInverse());
    return createRotation(inverse_transform);
}

Geometry::Transform3D RotationEuler::getTransform3D() const
{
    return Geometry::Transform3D::createRotateEuler(m_alpha, m_beta, m_gamma);
}