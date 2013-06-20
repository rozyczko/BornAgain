#ifndef SAMPLETOOLBAR_H
#define SAMPLETOOLBAR_H

#include <QToolBar>

class QAction;
class QToolButton;
class QToolBar;

//! main tool bar on top of SampleView window
class SampleToolBar : public QToolBar
{
    Q_OBJECT

public:
    explicit SampleToolBar(QWidget *parent = 0);

signals:
    void zoomIn();
    void zoomOut();
    void zoomFit();

public slots:
    void materialBrowserCall();

private:
    QAction *m_materialBrowserAction;
    QAction *m_zoomInAction;
    QAction *m_zoomOutAction;
    QAction *m_zoomFitAction;
};


#endif // SAMPLETOOLBAR_H