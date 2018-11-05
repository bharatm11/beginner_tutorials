#include "ros/ros.h"
#include "beginner_tutorials/ModifyString.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ModifyString");
  if (argc != 3)
  {
    ROS_INFO("usage: modifyString X");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::ModifyString>("ModifyString");
  beginner_tutorials::ModifyString srv;
  srv.request.num = atoll(argv[1]);
  if (client.call(srv))
  {
    ROS_INFO("%s", srv.response.name.c_str());
  }
  else
  {
    ROS_ERROR("Failed to call service ModifyString");
    return 1;
  }

  return 0;
}
