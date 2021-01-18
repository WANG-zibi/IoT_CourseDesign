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
#include <QtCharts/QChartView>//显示图表
#include <QtCharts/QLineSeries>//线系列
#include <QDoubleSpinBox>
#include <QGridLayout>
#include <QTimer>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>


QT_CHARTS_USE_NAMESPACE
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
    void RealtimeDataSlot();
private:
    void SetUI();
    void updateData();
    void initGraph();
    Ui::MainWindow *ui;
    DataBaseController* DBController;
    float tem;
    float ham;
    float light;
    QTimer *timer;

    QChart chart;
    QSplineSeries m_series;
    QStringList m_titles;
    QValueAxis m_axis;
    qreal m_step;
    qreal m_x;
    qreal m_y;
};
#endif // MAINWINDOW_H
