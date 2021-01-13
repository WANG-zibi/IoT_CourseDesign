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
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
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

