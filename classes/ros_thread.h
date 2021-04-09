#ifndef ROSTHREAD_H
#define ROSTHREAD_H

#include <QThread>
#include <iostream>
#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

class ROSThread : public QThread{

    Q_OBJECT

public:
    ROSThread(QObject * parent = nullptr);
    ~ROSThread() override;
    void ros_initialize(ros::NodeHandle &n);

    ros::Subscriber test_sub;

    ros::NodeHandle n_;
    

    void subscribe_callback(const sensor_msgs::ImagePtr& image);

    void run() override;

};

#endif