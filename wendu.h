#ifndef WENDU_H
#define WENDU_H

#include <QObject>
#include <QDebug>

class wendu : public QObject
{
    Q_OBJECT
public:

    ~wendu(){

        qDebug() << "wendu destroyed!\n";
    }
    wendu(const wendu&)=delete;
    wendu& operator=(const wendu&)=delete;
    static wendu& get_wendu();
    double num;

private:
    explicit wendu(QObject *parent = nullptr);


signals:

    public slots:
};

#endif // WENDU_H
