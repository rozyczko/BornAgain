// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/Components/SampleDesigner/DesignerMimeData.h
//! @brief     Defines class DesignerMimeData
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef DESIGNERMIMEDATA_H
#define DESIGNERMIMEDATA_H

#include "WinDllMacros.h"
#include <QMimeData>

class QDrag;
class QXmlStreamReader;

//! Mime data for use with SampleDesigner drag and drop operations
class BA_CORE_API_ DesignerMimeData : public QMimeData
{
    Q_OBJECT
public:
    DesignerMimeData(const QString &name, const QString &xmldescr, QDrag *drag);
    virtual ~DesignerMimeData(){}

    //! Execute a drag and drop operation.
    static Qt::DropAction execDrag(const QString &name, const QString &xmldescr, QWidget * dragSource);

    QString getClassName() const { return m_classname; }
private:
    void read_xmldescr(const QString &xmldescr);
    void read_widget(QXmlStreamReader &reader);

    QPixmap getPixmap(const QString &name);

    QString m_entryname;
    QString m_xmldescr;
    QString m_classname;

};

#endif // DESIGNERMIMEDATA_H
