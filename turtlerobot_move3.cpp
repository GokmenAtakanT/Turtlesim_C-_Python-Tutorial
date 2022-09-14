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



class turtle_class{
public:
float speed;
float distance;
float x;
float y;
float goal_x;
float goal_y;
float yaw;
ros::NodeHandle n;

	turtle_class(float goal_xa, float goal_ya,float x_a, float y_a,float yaw_a){
	x=x_a;
	y=y_a;
  goal_x=goal_xa;
  goal_y=goal_ya;
  yaw=yaw_a;
  //ros::log(x)
  move(goal_x,goal_y,x,y,yaw);

}

void move(float goal_x, float goal_y,float x, float y,float yaw){

  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
        std::cout << x<<std::endl;
        geometry_msgs::Twist velocity_message;
        float K_linear = 0.5 ;       
        distance = abs(sqrt( pow((goal_x-x) , 2) + pow((goal_y-y), 2)));
        speed = distance * K_linear;
        float K_angular = 2.0;
        float desired_angle_goal = atan2(goal_y-y, goal_x-x);
        float angular_speed = (desired_angle_goal-yaw)*K_angular;
        if(distance<0.01){
          angular_speed=0;
          speed=0;
        }
        velocity_message.linear.x =speed;
        velocity_message.angular.z =angular_speed;
        chatter_pub.publish(velocity_message);
        ros::spinOnce();
        //loop_rate.sleep();
        if(distance<0.01){
          ros::shutdown();
          

        }
  }


}

};

void poseCallback(const turtlesim::PoseConstPtr& pose_message)
{

    float x= pose_message->x;
    float y= pose_message->y;
    float yaw = pose_message->theta;
    float goal_x=10;
    float goal_y=10;
    turtle_class turtle_c1(goal_x,goal_y,x,y,yaw);
    //move(0.5,1);

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtle");


  ros::NodeHandle n;

  //ros::init(argc, argv, "my_tf_broadcaster");
  //if (argc != 2){ROS_ERROR("need turtle name as argument"); return -1;};
  //turtle_name = "turtle1";

  //ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("turtle1/pose", 1000, &poseCallback);
  ros::spin();
  //turtle turtle1(0.5,1);
  //loop_rate.sleep();

  return 0;
}
