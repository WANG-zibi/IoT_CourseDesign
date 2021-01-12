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
    //接受信息
    void ReceiveInfo(QSerialPort* m_serialPort,QString instruct);
    //发送信息
    void sendInfo(char *info, int len,QSerialPort* m_serialPort);
    int toNum(QString s);
    void ReceiveInfoFromLight();
    void ReceiveInfoFromTem();
    void sendInfo(QString&& info,QSerialPort* m_serialPort);
    //字符串转十六进制
    void convertStringToHex(const QString &str, QByteArray &byteData);
    //char转16进制
    char convertCharToHex(char ch);
    QStringList m_portNameList;
    //四个串口实例
    QSerialPort* SerialPorts[4];
};
#endif // SERIALPORT_H
