#include "roomcontrol.h"
#include "ui_roomcontrol.h"
#include<QDebug>


RoomControl::RoomControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoomControl)
{
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
    ui->setupUi(this);
    setWindowTitle("卧室");
    isCurtainOpen = false;
    QPixmap curtain(":/new/pic/images/curtain/curtain_close.png");
    ui->curtain->setPixmap(curtain);
    dengOn.load(":/new/prefix2/images/light/light_on1.png");
    dengOff.load(":/new/prefix2/images/light/light_off1.png");
    ui->deng1->setPixmap(dengOff);
    ui->deng2->setPixmap(dengOff);
    ui->deng3->setPixmap(dengOff);
    SwitchButton* SB;
    QPixmap kongtiao(":/new/prefix1/images/button/kongtiao.png");
    ui->kongtiao->setPixmap(kongtiao);
    SB = ui->pushButton;
    connect(SB,&SwitchButton::statusChanged,this,&RoomControl::onclicked);
    connect(ui->pushButton1,&SwitchButton::statusChanged,this,&RoomControl::onLight1Clicked);
    connect(ui->pushButton_2,&SwitchButton::statusChanged,this,&RoomControl::onLight2Clicked);
    connect(ui->pushButton_3,&SwitchButton::statusChanged,this,&RoomControl::onLight3Clicked);
    pre_windu = 0;
    pre_shidu = 0;
}

RoomControl::~RoomControl()
{
    delete ui;
}


void RoomControl::onclicked(bool isopen)
{
    if(isopen)
    {
        QPixmap curtain(":/new/pic/images/curtain/curtain_open.png");
        ui->curtain->setPixmap(curtain);
    }else
    {
        QPixmap curtain(":/new/pic/images/curtain/curtain_close.png");
        ui->curtain->setPixmap(curtain);

    }
}

void RoomControl::update()
{
    ui->lcdNumber->display(100);
}

void RoomControl::onLight1Clicked(bool isOpen)
{
    if(isOpen)
    {
        ui->deng1->setPixmap(dengOn);
    }
    else ui->deng1->setPixmap(dengOff);
}

void RoomControl::onLight2Clicked(bool isOpen)
{
    if(isOpen)
    {
        ui->deng2->setPixmap(dengOn);
    }
    else ui->deng2->setPixmap(dengOff);
}

void RoomControl::onLight3Clicked(bool isOpen)
{
    if(isOpen)
    {
        ui->deng3->setPixmap(dengOn);
    }
    else ui->deng3->setPixmap(dengOff);
}


void RoomControl::on_plus_clicked()
{
    pre_windu++;
    ui->lcdNumber_4->display(pre_windu);
}

void RoomControl::on_sub_clicked()
{
    pre_windu--;
    if(pre_windu<0) pre_windu = 0;
    ui->lcdNumber_4->display(pre_windu);
}

void RoomControl::on_plus_2_clicked()
{
    pre_shidu++;
    ui->lcdNumber_3->display(pre_shidu);
}

void RoomControl::on_sub_2_clicked()
{
    pre_shidu--;
    if(pre_shidu<0) pre_shidu = 0;
    ui->lcdNumber_3->display(pre_shidu);
}
