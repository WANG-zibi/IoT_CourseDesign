#include "graph.h"
#include "ui_graph.h"
#include "wendu.h"
#include "shidu_0.h"

Graph::Graph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graph)
{

        ui->setupUi(this);
        setWindowTitle("温湿度变化曲线图");
        timer = new QTimer;
        connect(timer,SIGNAL(timeout()),this,SLOT(RealtimeDataSlot()));
        timer->start(3000);
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
        chart.axisY()->setRange(0, 55);
        chart.axisY()->setTitleText("温湿度");
        QChartView *chartView = new QChartView(&chart);
        QGridLayout *baseLayout = new QGridLayout();
        baseLayout->addWidget(chartView, 0, 0);
        chartView->setRenderHint(QPainter::Antialiasing);
        ui->verticalLayout->addLayout(baseLayout);

        QPixmap kongtiao(":/new/prefix1/images/button/kongtiao.png");
        ui->kongtiao_2->setPixmap(kongtiao);
}
void Graph::RealtimeDataSlot() //在这里设置温湿度
{
    qreal y = 1.0;
    m_x += y;
    //m_y=sin(m_x);
    double nowTem; //当前温度
    double nowshi; //当前湿度

    wendu& wen = wendu :: get_wendu();
    shidu_0& shi = shidu_0 :: get_shidu();
    if(-300.0 < wen.num && wen.num < 30.0)
        nowTem = wen.num;
    if(shi.num >= 20.0)
        nowshi = shi.num;
    else {
        nowshi = 40.0;
    }
    m_series.append(m_x,nowTem);
    m_series1.append(m_x,nowshi);
//    chart.scroll(5,0);
    if(fit())
        ui->pushButton_6->change(true);
    else {
        ui->pushButton_6->change(false);
    }
}

bool Graph::fit()
{
    QList<QPointF> data;
    DataBaseController* DB_ptr = DataBaseController::GetInstance();
    data = DB_ptr->QueryData();
    if(data.empty()) return false;
    QVector<QPointF> curdata;
    if(data.size() > 11)
    {
    for(int i = data.size()-1; i >data.size() - 11;i--)
    {
        curdata.push_back(data[i]);
    }
    }
    else return 0;
    double k=0;
    double sum1,sumx,sumy,sumx2;
    sum1 = sumx = sumy = sumx2 = 0;
    for(auto i:curdata)
    {
        sum1+=i.rx()*i.ry();
        sumx += i.rx(),sumy+= i.ry();
        sumx2 +=i.rx()*i.rx();
    }
    k  = (10*sum1 - sumx*sumy) / (10*sumx2 - sumx*sumx);
    if(k > 0) return true;
    else return false;
}
Graph::~Graph()
{
    delete ui;
}
