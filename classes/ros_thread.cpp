#include "ros_thread.h"


ROSThread::ROSThread(){
    
}

ROSThread::~ROSThread(){

}

void ROSThread::ros_initialize(ros::NodeHandle &n){
    this->n_ = n;
    // test_sub = n_.subscribe("/camera/image/compressed", 1, boost::bind(&ROSThread::subscribe_callback, this, _1));
    test_sub = n_.subscribe("/camera/image/compressed", 1, subscribe_callback);

}

void ROSThread::subscribe_callback(const sensor_msgs::ImagePtr& image) {
    std::cout<<"Fucking Heard The Image"<<std::endl;
}