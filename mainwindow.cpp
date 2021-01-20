#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
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
    DateUpdate();
    TimeUpdate();
    w_graph = new Graph();
    w_Room = new RoomControl;
    w_model = new Model;
    QPixmap b1(":/new/prefix1/images/button/control.png");
    QPixmap b2(":/new/prefix1/images/button/setting.png");
    QPixmap b3(":/new/prefix1/images/button/statistics.png");
    ui->pushButton->setIcon(b1);
    ui->pushButton_3->setIcon(b2);
    ui->pushButton_4->setIcon(b3);
    //initGraph();
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update()
{
    updateData();
    DateUpdate();
    TimeUpdate();


}

void MainWindow::updateData()
{
    tem = Simulator::GenerateTemperature();
    ham = Simulator::GenerateHumidity();
    light = Simulator::GenerateLightIntensity();
    DBController->InsertData(QDate::currentDate().toString(),QTime::currentTime().toString(),tem,ham);
}

void MainWindow::DateUpdate()
{
 ui->hh->setText(QTime::currentTime().toString("hh"));
 ui->ss->setText(QTime::currentTime().toString("mm"));
}

void MainWindow::TimeUpdate()
{
    ui->year->setText(QDate::currentDate().toString("yyyy年MM月dd日"));
    ui->week->setText(QDate::currentDate().toString("dddd"));
}


void MainWindow::on_pushButton_clicked()
{
    w_Room->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    w_model->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    w_graph->show();
}
