#ifndef GUANGMIN_H
#define GUANGMIN_H

#include <QObject>
#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>
#include <math.h>
#include <QDebug>

#define		PCF     120
#define		DOpin	0


class guangmin : public QObject
{
    Q_OBJECT
public:

    ~guangmin(){

        qDebug() << "guangmin destroyed!\n";
    }
    guangmin(const guangmin&)=delete;
    guangmin& operator=(const guangmin&)=delete;
    static guangmin& get_guangmin();
    double num;
    bool flag = 1;

private:
    explicit guangmin(QObject *parent = nullptr);

signals:

public slots:
};

#endif // GUANGMIN_H

