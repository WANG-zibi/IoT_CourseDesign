#include "serialport.h"
#include <QDebug>

serialport::serialport()
{
    m_portNameList = getPortNameList();
}

QStringList serialport::getPortNameList()
{
    QStringList m_serialPortName;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        m_serialPortName << info.portName();
        qDebug()<<"serialPortName:"<<info.portName();
    }
    return m_serialPortName;
}

void serialport::ReceiveInfo(QSerialPort* m_serialPort)
{
            QByteArray info = m_serialPort->readAll();
            QByteArray hexData = info.toHex();
            //这里面的协议 你们自己定义就行  单片机发什么 代表什么 我们这里简单模拟一下
            if(hexData == "0x10000")
            {
                //do something
            }
            else if(hexData  == "0x100001")
            {
                //do something
            }
}

void serialport::sendInfo(char *info, int len,QSerialPort* m_serialPort)
{
    for(int i=0; i<len; ++i)
            {
                printf("0x%x\n", info[i]);
            }
    m_serialPort->write(info,len);//这句是真正的给单片机发数据 用到的是QIODevice::write 具体可以看文档
}

void serialport::sendInfo(QString&& info,QSerialPort* m_serialPort)
{
        QByteArray sendBuf;
        if (info.contains(" "))
        {
            info.replace(QString(" "),QString(""));//我这里是把空格去掉，根据你们定的协议来
        }
        qDebug()<<"Write to serial: "<<info;
        convertStringToHex(info, sendBuf); //把QString 转换 为 hex
        m_serialPort->write(sendBuf);
}

void serialport::convertStringToHex(const QString &str, QByteArray &byteData)
{
        int hexdata,lowhexdata;
        int hexdatalen = 0;
        int len = str.length();
        byteData.resize(len/2);
        char lstr,hstr;
        for(int i=0; i<len; )
        {
            //char lstr,
            hstr=str[i].toLatin1();
            if(hstr == ' ')
            {
                i++;
                continue;
            }
            i++;
            if(i >= len)
                break;
            lstr = str[i].toLatin1();
            hexdata = convertCharToHex(hstr);
            lowhexdata = convertCharToHex(lstr);
            if((hexdata == 16) || (lowhexdata == 16))
                break;
            else
                hexdata = hexdata*16+lowhexdata;
            i++;
            byteData[hexdatalen] = (char)hexdata;
            hexdatalen++;
        }
        byteData.resize(hexdatalen);
}

char serialport::convertCharToHex(char ch)
{
        /*
        0x30等于十进制的48，48也是0的ASCII值，，
        1-9的ASCII值是49-57，，所以某一个值－0x30，，
        就是将字符0-9转换为0-9
        */
        if((ch >= '0') && (ch <= '9'))
             return ch-0x30;
         else if((ch >= 'A') && (ch <= 'F'))
             return ch-'A'+10;
         else if((ch >= 'a') && (ch <= 'f'))
             return ch-'a'+10;
         else return (-1);
}



