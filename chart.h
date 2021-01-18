#pragma once
#ifndef CHART_H
#define CHART_H

#include <QtCharts/QChart>
#include<QtCharts\QChartView>   //两个基本模块
#include<QPointF>     //点类
#include<QList>         //列表
#include <QtCore/QTimer>   //定时器

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;                 //引入这两个类而免于引入整个头文件的方法
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE   //使用qtchart需要加入这条语句

//![1]
class Chart : public QChart
{
    Q_OBJECT
public:
    Chart(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = 0);
    QChartView *m_chartView;   //因为布局时其它函数会访问这个画布，所以设为public
    virtual ~Chart();
    void setPoint(QPointF& point);
private:
    QChart * m_chart;     //图表组件，可理解为画笔，用它画曲线
    QList<QSplineSeries *> m_serieslist;   //曲线列表，splineseries为光滑曲线

    QSplineSeries *m_series;     //曲线指针
    QStringList m_titles;             //标题
    QValueAxis *axisX;             //x坐标轴
    QValueAxis *axisY;             //y坐标轴
    QList<QPointF> curData;
    qreal m_step;
    qreal m_x;
    qreal m_y;
};
//![1]

#endif /* CHART_H */
