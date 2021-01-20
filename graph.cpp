#include "graph.h"
#include "ui_graph.h"
#include "windu.h"
Graph::Graph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graph)
{

        ui->setupUi(this);
        setWindowTitle("温湿度变化曲线图");
        timer = new QTimer;
        connect(timer,SIGNAL(timeout()),this,SLOT(RealtimeDataSlot()));
        timer->start(1000);
        m_x=0;
        m_y=0;
        chart.setTheme(QChart::ChartThemeBlueCerulean);//设置系统主题
        chart.setTitle("温湿度变化曲线图");//设置标题
        chart.setTitleFont(QFont("微软雅黑",10));
        chart.legend()->hide();
        QPen green(Qt::yellow);
        green.setWidth(2);
        m_series.setPen(green);
        m_series.append(m_x, m_y);
        QPen red(Qt::red);
        red.setWidth(2);
        m_series1.setPen(red);
        m_series1.append(m_x, m_y);
        chart.addSeries(&m_series);
        chart.addSeries(&m_series1);
        chart.createDefaultAxes();
        //chart.setAxisX(&m_axis,&m_series);
        m_axis.setTickCount(5);
        chart.axisX()->setRange(0,20);
        chart.axisX()->setTitleText("时间");
        chart.axisY()->setRange(0, 40);
        chart.axisY()->setTitleText("温湿度");
        QChartView *chartView = new QChartView(&chart);
        QGridLayout *baseLayout = new QGridLayout();
        baseLayout->addWidget(chartView, 0, 0);
        chartView->setRenderHint(QPainter::Antialiasing);
        ui->verticalLayout->addLayout(baseLayout);
}
void Graph::RealtimeDataSlot() //在这里设置温湿度
{
    qreal y = 1.0;
    m_x += y;
    //m_y=sin(m_x);
    double nowTem; //当前温度
    double nowshi; //当前湿度

    m_series.append(m_x,nowTem);
    m_series1.append(m_x,nowshi);
    chart.scroll(5,0);
}
Graph::~Graph()
{
    delete ui;
}
