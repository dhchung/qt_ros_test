#include <QThread>
#include <iostream>
#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

class ROSThread : public QThread{

public:
    ROSThread();
    ~ROSThread();
    void ros_initialize(ros::NodeHandle &n);

    ros::Subscriber test_sub;

    ros::NodeHandle n_;
    

    void subscribe_callback(const sensor_msgs::ImagePtr& image);
    
};