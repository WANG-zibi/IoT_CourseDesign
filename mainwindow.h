#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialport.h"
#include <QString>
#include "databasecontroller.h"
#include "simulator.h"
#include <QTimer>
#include <QTime>
#include <QDate>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


  private  slots: void update();
private:
    void SetUI();
    void updateData();
    Ui::MainWindow *ui;
    DataBaseController* DBController;
    float tem;
    float ham;
    float light;
    QTimer *timer;
};
#endif // MAINWINDOW_H
