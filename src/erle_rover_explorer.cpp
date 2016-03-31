#include <ros/ros.h>
#include <iostream>
#include <sensor_msgs/LaserScan.h>
#include <mavros/OverrideRCIn.h>
#include <mavros/State.h>

#define MAXRC 1900
#define MINRC 1100

// Subscriber to laser
ros::Subscriber sub;

// RC publisher
ros::Publisher pub;

double throttle, yaw;

void laserCallback(const sensor_msgs::LaserScan& msg)
{
    throttle = 0;
    yaw = 0;

    float angle = msg.angle_min;
    float angle_increment = msg.angle_increment;
    // Minimum and maximum range values (m)
    // Any value out of this bound should be discarded
    float range_min = msg.range_min;
    float range_max = msg.range_max;

    for (angle; angle < msg.angle_max; angle+=angle_increment)
    {
        // TO-DO
    }
     
    // Limit the throttle
    if (throttle > MAXRC)
    {
        throttle = MAXRC;
    } else if (throttle < MINRC)
    {
        throttle = MINRC;
    }

    // Limit the yaw
    if (yaw > MAXRC)
    {
        yaw = MAXRC;
    } else if (yaw < MINRC)
    {
        yaw = MINRC;
    }

    // Create RC msg
    mavros::OverrideRCIn rc_msg;
    rc_msg.channels[0] = 0;        //Roll
    rc_msg.channels[1] = 0;        //Pitch
    rc_msg.channels[2] = throttle; //Throttle
    rc_msg.channels[3] = yaw;      //Yaw
    rc_msg.channels[4] = 0;
    rc_msg.channels[5] = 0;
    rc_msg.channels[6] = 0;
    rc_msg.channels[7] = 0;

    pub.publish(rc_msg);

}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "erle_rover_explorer");
    ros::NodeHandle nh;
    sub = nh.subscribe("/scan", 1, laserCallback);
    ros::spin();
}