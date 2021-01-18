#ifndef ONLINEGRAPH_H
#define ONLINEGRAPH_H

#include <QWidget>
#include "QtCharts/QChart"
#include "QLineSeries"
#include "QValueAxis"
#include "QTimer"
#include "QTime"
#include "QList"
#include "qmath.h"
#include "QPointF"
#include "QDebug"
#include "QChartView"
QT_CHARTS_USE_NAMESPACE

class OnlineGraph : public QWidget
{
    Q_OBJECT
public:
    explicit OnlineGraph(QWidget *parent = nullptr);

signals:

};

#endif // ONLINEGRAPH_H
