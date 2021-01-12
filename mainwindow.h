#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QComboBox>
#include <QPushButton>
#include <QString>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initUI();
    int toNum(QString);
    QStringList getPortNameList();//获取所有可用的串口列表
    void openPort();//打开串口
public slots:
    void receiveInfo();
private:
    Ui::MainWindow *ui;
    QSerialPort* m_serialPort; //串口类
    QStringList m_portNameList;
    QComboBox* m_PortNameComboBox;
    QPushButton* m_OpenPortButton;
};
#endif // MAINWINDOW_H
