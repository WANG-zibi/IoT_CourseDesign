#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    DBController = DataBaseController::GetInstance();
    DBController->init();
    ui->setupUi(this);
    setWindowTitle("智能家居系统");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    initGraph();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RealtimeDataSlot()
{
    qreal y = 1.0;
    m_x += y;
    //m_y=sin(m_x);
    m_series.append(m_x,(double)tem);
    chart.scroll(5,0);
}
void MainWindow::update()
{
    updateData();
    SetUI();

    if(light <100.0f)
    {
        //开灯
    }
    else
    {
        //关灯
    }
    if(tem > 30.0f)
    {
        //开空调
    }
    else
    {
        //关空调
    }

}

void MainWindow::SetUI()
{
    ui->lineEdit->setText(QString::number(tem));
    ui->lineEdit_2->setText(QString::number(ham));
    ui->lineEdit_3->setText(QString::number(light));
}

void MainWindow::updateData()
{
    tem = Simulator::GenerateTemperature();
    ham = Simulator::GenerateHumidity();
    light = Simulator::GenerateLightIntensity();
    DBController->InsertData(QDate::currentDate().toString(),QTime::currentTime().toString(),tem,ham);
}

void MainWindow::initGraph()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(RealtimeDataSlot()));
    timer->start(1000);
    m_x=0;
    m_y=0;
    chart.setTheme(QChart::ChartThemeBlueCerulean);//设置系统主题
    chart.setTitle("温度变化图");//设置标题
    chart.setTitleFont(QFont("微软雅黑",10));
    chart.legend()->hide();
    QPen green(Qt::yellow);
    green.setWidth(2);
    m_series.setPen(green);
    m_series.append(m_x, m_y);
    chart.addSeries(&m_series);
    chart.createDefaultAxes();
    //chart.setAxisX(&m_axis,&m_series);
    m_axis.setTickCount(5);
    chart.axisX()->setRange(0,20);
    chart.axisX()->setTitleText("时间");
    chart.axisY()->setRange(0, 40);
    chart.axisY()->setTitleText("温度");
    QChartView *chartView = new QChartView(&chart);
    QGridLayout *baseLayout = new QGridLayout();
    baseLayout->addWidget(chartView, 0, 0);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout->addLayout(baseLayout);

}

