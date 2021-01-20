#include "switchbutton.h"
#include "ui_switchbutton.h"

SwitchButton::SwitchButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SwitchButton)
{
    ui->setupUi(this);
}

SwitchButton::~SwitchButton()
{
    delete ui;
}
