#include "PropertyVariantManager.h"
#include "DesignerHelper.h"
#include "MaterialBrowser.h"
#include <iostream>


PropertyVariantManager::PropertyVariantManager(QObject *parent)
    : QtVariantPropertyManager(parent)
{

}


int PropertyVariantManager::materialTypeId()
{
    return qMetaTypeId<MaterialProperty>();
}


bool PropertyVariantManager::isPropertyTypeSupported(int propertyType) const
{
    if (propertyType == materialTypeId())
        return true;
    return QtVariantPropertyManager::isPropertyTypeSupported(propertyType);
}


int PropertyVariantManager::valueType(int propertyType) const
{
    if (propertyType == materialTypeId())
        return materialTypeId();
    return QtVariantPropertyManager::valueType(propertyType);
}


QVariant PropertyVariantManager::value(const QtProperty *property) const
{
    if (theValues.contains(property)) {
        QVariant v;
        v.setValue(theValues[property]);
        return v;
    }
    return QtVariantPropertyManager::value(property);
}


QString PropertyVariantManager::valueText(const QtProperty *property) const
{
    if (theValues.contains(property)) {
        return theValues[property].getName();
    }
    return QtVariantPropertyManager::valueText(property);
}


QIcon PropertyVariantManager::valueIcon(const QtProperty *property) const
{
    if (theValues.contains(property)) {
        return QIcon(theValues[property].getPixmap());
    }
    return QtVariantPropertyManager::valueIcon(property);
}


void PropertyVariantManager::setValue(QtProperty *property, const QVariant &val)
{
    if (theValues.contains(property)) {
        if( val.userType() != materialTypeId() ) return;
        MaterialProperty mat = val.value<MaterialProperty>();
        theValues[property] = mat;
        QVariant v2;
        v2.setValue(mat);
        emit propertyChanged(property);
        emit valueChanged(property, v2);
        return;
    }
    QtVariantPropertyManager::setValue(property, val);
}


void PropertyVariantManager::initializeProperty(QtProperty *property)
{
    if (propertyType(property) == materialTypeId()) {
        MaterialProperty m;
        theValues[property] = m;
    }
    QtVariantPropertyManager::initializeProperty(property);
}


void PropertyVariantManager::uninitializeProperty(QtProperty *property)
{
    theValues.remove(property);
    QtVariantPropertyManager::uninitializeProperty(property);
}

