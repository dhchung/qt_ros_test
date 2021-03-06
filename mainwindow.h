#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleSpinBox>
#include "myglwidget.h"
#include "ros_thread.h"

#include <QMutex>
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QMutex mutex;
    ROSThread * ros_thread;

    void initialize_ros(ros::NodeHandle & n);

private slots:
    void on_rollSpinBox_valueChanged(double arg1);
    void on_pitchSpinBox_valueChanged(double arg1);
    void on_yawSpinBox_valueChanged(double arg1);
    void on_xSpinBox_valueChanged(double arg1);
    void on_ySpinBox_valueChanged(double arg1);
    void on_zSpinBox_valueChanged(double arg1);


    void on_updated_lidar1_signal();
    void on_updated_lidar2_signal();

private:
    Ui::MainWindow *ui;
    void update_glwidget();
};
#endif // MAINWINDOW_H
