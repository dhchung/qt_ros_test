#ifndef ROSTHREAD_H
#define ROSTHREAD_H

#include <QThread>
#include <iostream>
#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/PointCloud2.h>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

class ROSThread : public QThread{

    Q_OBJECT

public:
    ROSThread(QObject * parent = nullptr);
    ~ROSThread() override;
    void ros_initialize(ros::NodeHandle &n);

    ros::Subscriber test_sub;

    ros::Subscriber lidar1_sub;

    ros::NodeHandle n_;

    pcl::PointCloud<pcl::PointXYZI> lidar1_pc;
    

    void subscribe_callback(const sensor_msgs::CompressedImagePtr& image);

    void subscribe_lidar1_callback(const sensor_msgs::PointCloud2Ptr & ptcld);


    void run() override;

signals:
    void lidar1_signal();


};

#endif