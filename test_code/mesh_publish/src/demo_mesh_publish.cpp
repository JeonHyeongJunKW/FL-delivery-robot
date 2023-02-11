#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
int main(int argc, char **argv)
{
    ros::init(argc,argv,"demo_mesh_publisher");
    ros::NodeHandle n;

    ros::Publisher mesh_pub = n.advertise<sensor_msgs::PointCloud2>("mesh_data",1000);

    ros::Rate loop_rate(10);
    pcl::PointCloud<pcl::PointXYZRGB> point_xyz_rgb;
    sensor_msgs::PointCloud2 msg_data;
    
    //mesh data 1,2,3 input
    pcl::PointXYZRGB p1;
    p1.x =0;
    p1.y=0;
    p1.z=0;
    p1.r = 255;
    p1.g =0;
    p1.b = 0;
    point_xyz_rgb.push_back(p1);

    pcl::PointXYZRGB p2;
    p2.x =0;
    p2.y=1;
    p2.z=0;
    p2.r = 0;
    p2.g = 255;
    p2.b = 0;
    point_xyz_rgb.push_back(p2);

    pcl::PointXYZRGB p3;
    p3.x =0;
    p3.y=0;
    p3.z=1;
    p3.r = 0;
    p3.g = 0;
    p3.b = 255;
    point_xyz_rgb.push_back(p3);

    pcl::toROSMsg(point_xyz_rgb,msg_data);
    msg_data.header.frame_id = "map";

    
    while(ros::ok())
    {
        ros::spinOnce();
        mesh_pub.publish(msg_data);
        loop_rate.sleep();

    }
    return 0;
}