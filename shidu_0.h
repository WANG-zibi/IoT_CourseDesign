#ifndef SHIDU_0_H
#define SHIDU_0_H

#include <QObject>
#include <QDebug>

class shidu_0 : public QObject
{
    Q_OBJECT
public:

    ~shidu_0(){

        qDebug() << "shidu_0 destroyed!\n";
    }
    shidu_0(const shidu_0&)=delete;
    shidu_0& operator=(const shidu_0&)=delete;
    static shidu_0& get_shidu();
    double num;

private:
    explicit shidu_0(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SHIDU_0_H



