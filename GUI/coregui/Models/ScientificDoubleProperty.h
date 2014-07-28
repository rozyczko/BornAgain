#ifndef SCIENTIFICDOUBLEPROPERTY_H
#define SCIENTIFICDOUBLEPROPERTY_H

#include <QMetaType>
#include <QString>
#include <QVariant>

//! The ScientificDoubleProperty for ParameterizedItem and PropertyEditor
//!
//! The reason is to have simple editor for doubles in scientific notation
//! in PropertyEditor instead of inconvenient QDoubleSpinBox
class ScientificDoubleProperty
{
public:
    explicit ScientificDoubleProperty(double value = 0) : m_value(value) {}
    double getValue() const { return m_value;}
    void setValue(double value) { m_value = value; }
    QString getText() const { return QString::number(m_value,'g');}
    QVariant getVariant() const {
        QVariant result;
        result.setValue(*this);
        return result;
    }

private:
    double m_value;
};

Q_DECLARE_METATYPE(ScientificDoubleProperty)


#endif
