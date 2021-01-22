#include "roomcontrol.h"
#include "ui_roomcontrol.h"
#include<QDebug>
#include "shidu_0.h"
#include "guangmin.h"
#include <math.h>


RoomControl::RoomControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoomControl)
{
    timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
//    timer->start(1000);
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
    SB = ui->pushButton_4;
    connect(SB,&SwitchButton::statusChanged,this,&RoomControl::onclicked);
    connect(ui->pushButton1,&SwitchButton::statusChanged,this,&RoomControl::onLight1Clicked);
    connect(ui->pushButton_2,&SwitchButton::statusChanged,this,&RoomControl::onLight2Clicked);
    connect(ui->pushButton_3,&SwitchButton::statusChanged,this,&RoomControl::onLight3Clicked);



//    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(3000);


    wendu& wen = wendu :: get_wendu();
    shidu_0& shi = shidu_0 :: get_shidu();

    ui->lcdNumber_4->display(int(wen.num));
    while(shi.num == 0){
        shidu_0& shi = shidu_0 :: get_shidu();
    }
    ui->lcdNumber_3->display(int(shi.num));
    pre_windu = wen.num;
    pre_shidu = shi.num;
    windu = 0;
    shidu = 0;
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

    wendu& wen = wendu :: get_wendu();
    shidu_0& shi = shidu_0 ::get_shidu();

     guangmin& guang = guangmin :: get_guangmin();
    double num_wen,
           num_shi,
           num_guang = 300 - guang.num;
    if(wen.num != -300.0)
        num_wen = wen.num;
    if(num_shi != 0)
        num_shi = shi.num;


    ui->lcdNumber_2->display(num_shi);
    ui->lcdNumber->display(num_wen);
    ui->lcdNumber_5->display(num_guang);
    if(num_guang >= 180.0)
        ui->pushButton_4->change(true);
    else
        ui->pushButton_4->change(false);
    double need_wen = ui->lcdNumber_4->value(), need_shi = ui->lcdNumber_3->value();
    if((fabs(need_wen - num_wen) <= 1.5) && (fabs(need_shi - num_shi) <= 2))
        ui->pushButton_5->change(false);
    else
        ui->pushButton_5->change(true);

//    qDebug() << ui->lcdNumber->value();
}

void RoomControl::onLight1Clicked(bool isOpen)
{

    if(isOpen)
    {
        led& ld = led :: led_lighten();
        ui->deng1->setPixmap(dengOn);
    }
    else{
       led& ld = led :: led_crash_out();
        ui->deng1->setPixmap(dengOff);
    }
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


