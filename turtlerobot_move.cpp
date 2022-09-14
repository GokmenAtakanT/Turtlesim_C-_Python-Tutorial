#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <cmath>
#include <ctime>
#include <cstdlib>

//#include "std_srvs.srv/Empty"
#include <std_srvs/Empty.h>

class turtle{
public:
float speed;
float distance;
float x;
float y;
float yaw;
ros::NodeHandle n;

	turtle(float speed_a, float distance){
	speed=speed_a;
	distance=distance;
  move(speed,distance);

}

void move(float speed, float distance){

  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    geometry_msgs::Twist velocity_message;
    velocity_message.linear.x =speed;
    chatter_pub.publish(velocity_message);

    ros::spinOnce();

    loop_rate.sleep();
  }


}

};





int main(int argc, char **argv)
{


  ros::init(argc, argv, "turtle");



  turtle turtle1(0.5,1);
  //move(0.5,1);

  return 0;
}
