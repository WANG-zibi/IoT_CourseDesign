#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
class serialport:public QObject
{
        Q_OBJECT
public:
    serialport(){}
    QStringList getPortNameList();
    virtual void ReceiveInfo(QSerialPort* m_serialPort);
    virtual void sendInfo(char *info, int len,QSerialPort* m_serialPort);
    virtual void sendInfo(QString&& info,QSerialPort* m_serialPort);
    void convertStringToHex(const QString &str, QByteArray &byteData);
    char convertCharToHex(char ch);
};

#endif // SERIALPORT_H
