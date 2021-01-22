#include "led.h"

led::led(QObject *parent) : QObject(parent)
{
    if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
        qDebug() << "setup wiringPi failed !";
        return ;
    }
    pinMode(LedPinRed, OUTPUT);
    qDebug() << "led build!";
}


led& led :: led_lighten()
{

    static led single;
    if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
        qDebug() << "setup wiringPi failed !";
        return single;
    }
    digitalWrite(LedPinRed, HIGH);
    qDebug() << "led lighten!";
    delay(500);
    return single;
}
led& led :: led_crash_out()
{
    static led single;

    if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
        qDebug() << "setup wiringPi failed !";
        return single;
    }

//    softPwmCreate(LedPinRed,  0, 100);
    digitalWrite(LedPinRed, LOW);
    delay(500);
    qDebug() << "led crash out!";
    return single;
}
led& led :: is_led_open()
{
    static led single;
    if(digitalRead(LedPinRed) == HIGH)
        single.status = 1;
    else {
        single.status = 0;
    }

    return single;
}
