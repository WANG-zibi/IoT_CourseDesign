#include "roomcontrol.h"
#include "ui_roomcontrol.h"

RoomControl::RoomControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoomControl)
{
    ui->setupUi(this);
}

RoomControl::~RoomControl()
{
    delete ui;
}
