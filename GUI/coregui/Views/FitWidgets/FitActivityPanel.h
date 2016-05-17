// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/FitWidgets/FitActivityPanel.h
//! @brief     Declares class FitActivityPanel
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef FITACTIVITYPANEL_H
#define FITACTIVITYPANEL_H

#include "JobPresenter.h"
#include <QMap>

class JobModel;
class JobItem;
class QStackedWidget;
class FitSuiteWidget;
class JobRealTimeWidget;
class RunFitControlWidget;

//! Main widget to run fitting. Occupies bottom right corner of JobView.
//! Contains stack of FitSuiteWidgets for JobItem's suitable for fitting.

class BA_CORE_API_ FitActivityPanel : public JobPresenter
{
    Q_OBJECT
public:
    FitActivityPanel(JobModel *jobModel, QWidget *parent = 0);

    void setRealTimeWidget(JobRealTimeWidget *realTimeWidget);

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

public slots:
    void setItem(JobItem *item);
    void onJobItemDelete(JobItem *item);
    void onJobItemFinished(const QString &identifier);
    void updateCurrentItem();

private slots:
    void onStartFitting();
    void onStopFitting();

private:
    bool isValidJobItem(JobItem *item);
    FitSuiteWidget *getCurrentFitSuiteWidget();

    QStackedWidget *m_stack;
    RunFitControlWidget *m_controlWidget;
    QMap<JobItem *, FitSuiteWidget *> m_jobItemToFitWidget;
    JobRealTimeWidget *m_realTimeWidget;
};

#endif