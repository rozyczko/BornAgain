#include "DataViewUtils.h"
#include "DataItem.h"
#include "Data1DViewItem.h"
#include "DomainObjectBuilder.h"
#include "JobItem.h"
#include "JobItemUtils.h"
#include "DataPropertyContainer.h"
#include "UnitConverterUtils.h"

namespace {
std::unique_ptr<IUnitConverter> getConverter(Data1DViewItem* view_item)
{
    auto job_item = view_item->jobItem();
    assert(job_item->instrumentItem());

    return DomainObjectBuilder::createUnitConverter(job_item->instrumentItem());
}

AxesUnits selectedUnits(Data1DViewItem* view_item)
{
    auto current_unit_name
        = view_item->getItemValue(Data1DViewItem::P_AXES_UNITS).value<ComboProperty>().getValue();
    return JobItemUtils::axesUnitsFromName(current_unit_name);
}
}

void DataViewUtils::updateAxesTitle(Data1DViewItem* view_item)
{
    auto converter = getConverter(view_item);
    if (!converter)
        return;
    auto current_units = selectedUnits(view_item);
    view_item->setXaxisTitle(QString::fromStdString(converter->axisName(0, current_units)));
    if (converter->dimension() > 1)
        view_item->setYaxisTitle(QString::fromStdString(converter->axisName(1, current_units)));
}

std::unique_ptr<OutputData<double>> DataViewUtils::getTranslatedData(Data1DViewItem* view_item,
                                                                     DataItem* data_item)
{
    std::unique_ptr<OutputData<double>> result;
    if (!data_item || !data_item->getOutputData())
        return result;

    auto converter = getConverter(view_item);
    auto current_units = selectedUnits(view_item);

    result = UnitConverterUtils::createOutputData(*converter, current_units);
    result->setRawDataVector(data_item->getOutputData()->getRawDataVector());

    return result;
}
