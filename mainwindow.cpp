#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ros_thread = new ROSThread(this);
    ros_thread->start();


    connect(ros_thread, SIGNAL(lidar1_signal()), this, SLOT(on_updated_lidar1_signal()));
    connect(ros_thread, SIGNAL(lidar2_signal()), this, SLOT(on_updated_lidar2_signal()));

}

MainWindow::~MainWindow()
{
    // if(ros::master::check()) {
    //     system("/home/dongha/kill_roscore.sh");
    // }

    ros_thread->terminate();

    ros_thread->quit();


    delete ui;
}

void MainWindow::initialize_ros(ros::NodeHandle & n){
    ros_thread->ros_initialize(n);
}

void MainWindow::update_glwidget(){
    ui->renderWindow->paintstuff();
}

void MainWindow::on_rollSpinBox_valueChanged(double arg1)
{
    ui->renderWindow->set_roll(static_cast<float>(arg1));
    update_glwidget();
}



void MainWindow::on_pitchSpinBox_valueChanged(double arg1)
{
    ui->renderWindow->set_pitch(static_cast<float>(arg1));
    update_glwidget();
}

void MainWindow::on_yawSpinBox_valueChanged(double arg1)
{
    ui->renderWindow->set_yaw(static_cast<float>(arg1));
    update_glwidget();
}

void MainWindow::on_xSpinBox_valueChanged(double arg1)
{
    ui->renderWindow->set_x(static_cast<float>(arg1));
    update_glwidget();
}

void MainWindow::on_ySpinBox_valueChanged(double arg1)
{
    ui->renderWindow->set_y(static_cast<float>(arg1));
    update_glwidget();
}


void MainWindow::on_zSpinBox_valueChanged(double arg1)
{
    ui->renderWindow->set_z(static_cast<float>(arg1));
    update_glwidget();
}


void MainWindow::on_updated_lidar1_signal(){

    std::vector<std::vector<float>> pc;
    pc.resize(ros_thread->lidar1_pc.size());
    for(int pid = 0; pid < ros_thread->lidar1_pc.size(); ++pid) {
        pc[pid].resize(3);
        pc[pid][0] = ros_thread->lidar1_pc[pid].x;
        pc[pid][1] = ros_thread->lidar1_pc[pid].y;
        pc[pid][2] = ros_thread->lidar1_pc[pid].z;
    }
    ui->renderWindow->lidar1_ptcld = pc;

    ui->renderWindow->paintstuff();
}

void MainWindow::on_updated_lidar2_signal(){

    std::vector<std::vector<float>> pc;
    pc.resize(ros_thread->lidar2_pc.size());
    for(int pid = 0; pid < ros_thread->lidar2_pc.size(); ++pid) {
        pc[pid].resize(3);
        pc[pid][0] = ros_thread->lidar2_pc[pid].x;
        pc[pid][1] = ros_thread->lidar2_pc[pid].y;
        pc[pid][2] = ros_thread->lidar2_pc[pid].z;
    }
    ui->renderWindow->lidar2_ptcld = pc;
    ui->renderWindow->paintstuff();
}


