#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_glwidget(){
    ui->renderWindow->paintstuff();
}

void MainWindow::on_rollSpinBox_valueChanged(double arg1)
{
    ui->renderWindow->set_roll(static_cast<float>(arg1));
    // std::cout<<"Roll Changed to "<<arg1<<std::endl;
    update_glwidget();
}



void MainWindow::on_pitchSpinBox_valueChanged(double arg1)
{
    ui->renderWindow->set_pitch(static_cast<float>(arg1));
    // std::cout<<"Pitch Changed to "<<arg1<<std::endl;
    update_glwidget();
}

void MainWindow::on_yawSpinBox_valueChanged(double arg1)
{
    ui->renderWindow->set_yaw(static_cast<float>(arg1));
    // std::cout<<"Yaw Changed to "<<arg1<<std::endl;
    update_glwidget();
}

void MainWindow::on_xSpinBox_valueChanged(double arg1)
{
    ui->renderWindow->set_x(static_cast<float>(arg1));
    // std::cout<<"x Changed to "<<arg1<<std::endl;
    update_glwidget();
}

void MainWindow::on_ySpinBox_valueChanged(double arg1)
{
    ui->renderWindow->set_y(static_cast<float>(arg1));
    // std::cout<<"y Changed to "<<arg1<<std::endl;
    update_glwidget();
}


void MainWindow::on_zSpinBox_valueChanged(double arg1)
{
    ui->renderWindow->set_z(static_cast<float>(arg1));
    // std::cout<<"z Changed to "<<arg1<<std::endl;
    update_glwidget();
}