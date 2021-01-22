#ifndef LED_H
#define LED_H

#include <QObject>
#include <QDebug>
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define uchar unsigned char

#define LedPinRed    1

class led : public QObject
{
    Q_OBJECT
public:

    ~led(){

        qDebug() << "led destroyed!\n";
    }
    led(const led&)=delete;
    led& operator=(const led&)=delete;
    static led& led_lighten();
    static led& led_crash_out();
    static led& is_led_open();
    bool status;
private:
    explicit led(QObject *parent = nullptr);

signals:

public slots:
};

#endif // LED_H

