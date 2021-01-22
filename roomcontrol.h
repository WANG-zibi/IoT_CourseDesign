#ifndef ROOMCONTROL_H
#define ROOMCONTROL_H

#include <QWidget>
#include <QPixmap>
#include"switchbutton.h"
#include"QTimer"
#include "wendu.h"
#include "led.h"
#include "shidu_0.h"
#include "guangmin.h"


namespace Ui {
class RoomControl;
}

class RoomControl : public QWidget
{
    Q_OBJECT

public:
    explicit RoomControl(QWidget *parent = nullptr);
    ~RoomControl();

public slots:
     void update();

private slots:
    void onclicked(bool isopen);

    void onLight1Clicked(bool isOpen);
    void onLight2Clicked(bool isOpen);
    void onLight3Clicked(bool isOpen);
    void on_plus_clicked();

    void on_sub_clicked();

    void on_plus_2_clicked();

    void on_sub_2_clicked();

    void on_pushButton_clicked(bool checked);

    void on_plus_clicked(bool checked);

private:
    Ui::RoomControl *ui;
    bool isCurtainOpen;
    void SetCurtain();
    QTimer* timer;
    QPixmap dengOn;
    QPixmap dengOff;
    float windu;
    float shidu;
    float pre_windu;
    float pre_shidu;
};

#endif // ROOMCONTROL_H
