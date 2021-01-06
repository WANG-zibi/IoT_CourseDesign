#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QDebug>
#include <QString>

int MainWindow::toNum(QString s)
{


    char*  ch;
    QByteArray ba = s.toLatin1(); // must
    ch=ba.data();

    int res = 0;
    for(int i = 10; i < 14; i ++)
           res = (res << 4) + (ch[i] - ('0' <= s[i] && s[i] <= '9'? '0': 'a' - 10));
    return res;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_serialPort = new QSerialPort();
    initUI();
    m_portNameList = getPortNameList();
    m_PortNameComboBox->addItems(m_portNameList);
    connect(m_OpenPortButton,&QPushButton::clicked,this,&MainWindow::openPort);
}

MainWindow::~MainWindow()
{
    if (m_serialPort->isOpen())
    {
        m_serialPort->close();
    }
    delete m_serialPort;

    delete ui;
}

void MainWindow::initUI()
{
    this->setWindowTitle("test QSerialPort");
    m_OpenPortButton = new QPushButton();
    m_OpenPortButton->setText("打开串口");
    m_PortNameComboBox  = new QComboBox();
    QHBoxLayout *m_layout = new QHBoxLayout();
    m_layout->addWidget(m_PortNameComboBox);
    m_layout->addWidget(m_OpenPortButton);
    QWidget * widget = new QWidget ();
    widget->setLayout(m_layout);
    this-> setCentralWidget(widget) ;
}

QStringList MainWindow::getPortNameList()
{
    QStringList m_serialPortName;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        m_serialPortName << info.portName();
        qDebug()<<"serialPortName:"<<info.portName();
    }
    return m_serialPortName;
}

void MainWindow::openPort()
{
    if(m_serialPort->isOpen())//如果串口已经打开了 先给他关闭了
    {
        m_serialPort->clear();
        m_serialPort->close();
    }
    m_serialPort->setPortName(m_PortNameComboBox->currentText());//当前选择的串口名字

    if(!m_serialPort->open(QIODevice::ReadWrite))//用ReadWrite 的模式尝试打开串口
    {
        qDebug()<<"打开失败!";
        return;
    }
    qDebug()<<"串口打开成功!";

    m_serialPort->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);//设置波特率和读写方向
    m_serialPort->setDataBits(QSerialPort::Data8);      //数据位为8位
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);//无流控制
    m_serialPort->setParity(QSerialPort::NoParity); //无校验位
    m_serialPort->setStopBits(QSerialPort::OneStop); //一位停止位

    connect(m_serialPort,SIGNAL(readyRead()),this,SLOT(receiveInfo()));
}

//接收到单片机发送的数据进行解析
void MainWindow::receiveInfo()
{
    QByteArray info = m_serialPort->readAll();

    //m_serialPort->write();

    QByteArray str = info.toHex();
    QString s = str;
    qDebug()<<"receive info:"<<info;
    qDebug() << str;
    qDebug() << 1.0 * toNum(s) / 100.0 << "\n";


}




void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}
