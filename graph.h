#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include <QTimer>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QGridLayout>
#include "databasecontroller.h"

QT_CHARTS_USE_NAMESPACE
namespace Ui {
class Graph;
}

class Graph : public QWidget
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();
private slots: void RealtimeDataSlot();

private:
    Ui::Graph *ui;
    QTimer *timer;
    QChart chart;
    QSplineSeries m_series;
    QSplineSeries m_series1;
    QStringList m_titles;
    QValueAxis m_axis;
    qreal m_step;
    qreal m_x;
    qreal m_y;

    bool fit();
};

#endif // GRAPH_H
