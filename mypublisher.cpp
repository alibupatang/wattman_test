/*************************************************************************
	> File Name: mypublisher.cpp
	> Author: csgec
	> Mail: 12345678@qq.com 
	> Created Time: 2021年06月03日 星期四 17时09分56秒
 ************************************************************************/

#include<iostream>

#include<ros/ros.h>                                                                                                                                
#include<std_msgs/String.h>
#include<std_msgs/Int8.h>

#include<sstream>

int main(int argc, char **argv)
{
    ros::init(argc,argv,"mypublisher");

    ros::NodeHandle n;

	ros::Publisher test_name_pub = n.advertise<std_msgs::String>("/test_name",10);

    ros::Publisher test_index_pub = n.advertise<std_msgs::Int8>("/test_index",10);

    ros::Rate loop_rate(1);
 
    int count = 0;
    
	std_msgs::Int8 num;
	num.data = 0;

	std_msgs::String msg;
	std::stringstream ss;
	ss <<"wattman"; 
	msg.data = ss.str();

    while (ros::ok())
    {
//		if(num.data > 10)
//			break;

        test_name_pub.publish(msg);
        test_index_pub.publish(num);
		
		ROS_INFO("%s",msg.data.c_str());
		ROS_INFO("%d",num.data);
		
		num.data++;
		loop_rate.sleep();
    }
    return 0;
}
