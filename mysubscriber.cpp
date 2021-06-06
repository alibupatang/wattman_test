/*************************************************************************
	> File Name: mysubscriber.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2021年06月04日 星期五 14时25分34秒
 ************************************************************************/

#include <ros/ros.h>
#include </usr/include/pcl-1.8/pcl/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/io/pcd_io.h>
#include <pcl_ros/point_cloud.h>


void cloudCB(const sensor_msgs::PointCloud2 &input)
{
    pcl::PointCloud<pcl::PointXYZ> cloud;
    pcl::fromROSMsg(input, cloud);
    pcl::io::savePCDFileASCII ("/test.pcd", cloud);
}
main (int argc, char **argv)
{
    ros::init (argc, argv, "mysub");

    ROS_INFO("Started PCL write node");

    ros::NodeHandle nh;
    ros::Subscriber bat_sub = nh.subscribe("livox/lidar", 1, cloudCB);

    ros::spin();
    return 0;
}


