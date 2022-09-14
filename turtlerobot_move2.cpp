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
#include <tf/transform_broadcaster.h>



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

void poseCallback(const turtlesim::PoseConstPtr& pose_message)
{

    float x= pose_message->x;
    float y= pose_message->y;
    float yaw = pose_message->theta;
    std::cout << x<<std::endl;
    turtle turtle1(0.5,1);
    //move(0.5,1);

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtle");
  //ros::Rate loop_rate(10);
  ros::NodeHandle n;


  //ros::init(argc, argv, "my_tf_broadcaster");
  //if (argc != 2){ROS_ERROR("need turtle name as argument"); return -1;};
  //turtle_name = "turtle1";

  //ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("turtle1/pose", 10, &poseCallback);
  ros::spin();
  //turtle turtle1(0.5,1);
  //loop_rate.sleep();

  return 0;
}
