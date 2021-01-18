#include "chart.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QTime>
#include <QtCore/QDebug>
#include <QPen>
#include<QPainter>
#include<QtCharts\QLegendMarker>
#include<qmath.h>
#include "databasecontroller.h"
Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags) :QChart(QChart::ChartTypeCartesian, parent, wFlags)
{
    m_chart = new QChart;
    m_chartView = new QChartView(m_chart);
    m_chartView->setRubberBand(QChartView::RectangleRubberBand);  //矩形缩放
    //设置x坐标轴
    axisX = new QValueAxis;
    axisX->setRange(0, 1000);  //范围
    axisX->setLabelFormat("%d"); //图例的格式  %d为十进制显示
    axisX->setGridLineVisible(true);//网格
    axisX->setTickCount(5);   //主要刻度
//    axisX->setMinorTickCount(10);//小刻度
    axisX->setTitleText("时间");//标题
    //设置y坐标轴
    axisY = new QValueAxis;
    axisY->setRange(0.0, 40.0);
    axisY->setLabelFormat("%.2lf");
    axisY->setGridLineVisible(true);
    axisY->setTickCount(5);
    //axisY->setMinorTickCount(10);
    axisY->setTitleText("温度");

    m_chart->addAxis(axisX, Qt::AlignBottom);  //将坐标轴加到chart上，居下
    m_chart->addAxis(axisY, Qt::AlignLeft);//居左

    m_chart->setTitle("温度曲线图");   //设置图表标题

    m_chart->legend()->setVisible(true);  //设置图例可见
    m_series = new QSplineSeries();
    m_series->setName("温度曲线");
    m_chart->addSeries(m_series);
}

Chart::~Chart()
{

}

void Chart::setPoint(QPointF &point)
{
    m_series->append(point);
}


