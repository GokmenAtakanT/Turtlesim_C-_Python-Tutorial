#include <ros/ros.h>
//The srv class for the service.
#include <turtlesim/TeleportAbsolute.h>

int main(int argc, char **argv){

   ros::init(argc, argv, "teloport_turtle");
   ros::NodeHandle nh;

//Create a client object for the spawn service. This
//needs to know the data type of the service and its name.
   ros::ServiceClient spawnClient= nh.serviceClient<turtlesim::TeleportAbsolute>("turtle1/teleport_absolute");

//Create the request and response objects.
   turtlesim::TeleportAbsolute::Request req;
   turtlesim::TeleportAbsolute::Response resp;

   req.x = 10;
   req.y = 10;
   req.theta = M_PI/2;
   //req.name = "turtle1";

   ros::service::waitForService("turtle1/teleport_absolute", ros::Duration(5));
   bool success = spawnClient.call(req,resp);

   if(success){
       ROS_INFO_STREAM("Spawned a turtle named ");
   }else{
       ROS_ERROR_STREAM("Failed to spawn.");
   }
}