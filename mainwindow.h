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
#include "graph.h"
#include "roomcontrol.h"
#include "model.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private  slots:
    void update();
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    void SetUI();
    void updateData();
    void initGraph();
    void DateUpdate();
    void TimeUpdate();
    Ui::MainWindow *ui;
    DataBaseController* DBController;
    float tem;
    float ham;
    float light;
    QTimer *timer;
    Graph* w_graph;
    RoomControl* w_Room;
    Model* w_model;

};
#endif // MAINWINDOW_H
