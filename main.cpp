#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <ros/ros.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ros::init(argc, argv, "sensor_driver_viewer");

    if(ros::master::check()){
        std::cout<<"ros_maeter_is_on"<<std::endl;
    }else {
        std::cout<<"ros_master_is_off"<<std::endl;
    }

    if(!ros::master::check()){
        system("/home/dongha/run_roscore.sh");
    }
    // if(!ros::master::check()){
    //     return 0;
    // }
    ros::NodeHandle nh;

    MainWindow w;
    w.show();


    return a.exec();
}
