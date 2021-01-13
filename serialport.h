#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
/*
 *串口通信
 * 对于传感器以及电机、灯光的控制
 **/
class serialport:public QObject
{
        Q_OBJECT
public:
    serialport();
    QStringList getPortNameList();
    void ReceiveInfoFromLight();
    void ReceiveInfoFromTem();

    void convertStringToHex(const QString &str, QByteArray &byteData);
    //char转16进制
    char convertCharToHex(char ch);
    QStringList m_portNameList;
    //四个串口实例
    QSerialPort* SerialPorts[4];

    bool isLighting;
    bool isHot;
};
#endif // SERIALPORT_H
