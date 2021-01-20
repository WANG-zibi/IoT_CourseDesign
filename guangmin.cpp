#include "guangmin.h"
#include <QObject>
#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>
#include <math.h>
#include <QDebug>

#define		PCF     120
#define		DOpin	0

guangmin::guangmin(QObject *parent) : QObject(parent)
{
    qDebug() << "guangmin build!";
}

guangmin& guangmin :: get_guangmin()
{
    static guangmin single;
    single.num = -1;
    int analogVal;

    if(wiringPiSetup() == -1){
        qDebug() << "setup wiringPi failed !";
        return single;
    }
    // Setup pcf8591 on base pin 120, and address 0x48
    if(single.flag){
        pcf8591Setup(PCF, 0x48);
        single.flag = 0;
    }

    while(1) // loop forever
    {
        analogVal = analogRead(PCF + 0);
        if(analogVal != 128){

            qDebug() << "Value: " << analogVal;
            single.num = analogVal;
            return single;
        }

        delay (200);
    }

    return single;
}

