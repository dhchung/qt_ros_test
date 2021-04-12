#include "ros_thread.h"


ROSThread::ROSThread(QObject * parent)
// : QThread(parent)
{
    
}

ROSThread::~ROSThread(){

}

void ROSThread::ros_initialize(ros::NodeHandle &n){
    this->n_ = n;
    test_sub = n_.subscribe("/camera/image/compressed", 1, &ROSThread::subscribe_callback, this);
    lidar1_sub = n_.subscribe("/lidar1/os_cloud_node/points", 1, &ROSThread::subscribe_lidar1_callback, this);
    lidar2_sub = n_.subscribe("/lidar2/os_cloud_node/points", 1, &ROSThread::subscribe_lidar2_callback, this);
}

void ROSThread::subscribe_callback(const sensor_msgs::CompressedImagePtr& image) {


}

void ROSThread::subscribe_lidar1_callback(const sensor_msgs::PointCloud2Ptr & ptcld) {

    // pcl::fromPCLPointCloud2(*ptcld, lidar1_pc);
    pcl::fromROSMsg(*ptcld, lidar1_pc);
    
    emit lidar1_signal();
}


void ROSThread::subscribe_lidar2_callback(const sensor_msgs::PointCloud2Ptr & ptcld) {
    pcl::fromROSMsg(*ptcld, lidar2_pc);
    emit lidar2_signal();
}


void ROSThread::run(){
    ros::AsyncSpinner spinner(0);
    spinner.start();
    ros::waitForShutdown();
}