// "Copyright [2018] <Bharat Mathur>"
/** @file ModifyString.cpp
  *  @brief ModifyString.cpp is a node that serves as a client to request a
  *ChangeString service.
  *
  *  @author Bharat Mathur (bharatm11)
  *  @bug No known bugs.
  *  @copyright GNU Public License.
*/
#include <cstdlib>
#include "beginner_tutorials/ModifyString.h"
#include "ros/ros.h"


int main(int argc, char **argv) {
  ros::init(argc, argv, "ModifyString");
  if (argc != 3) {
    ROS_ERROR("usage: modifyString X");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::ModifyString>
  ("ModifyString");
  beginner_tutorials::ModifyString srv;
  srv.request.num = atoll(argv[1]);
  if (client.call(srv)) {
    ROS_INFO("%s", srv.response.name.c_str());
  } else {
    ROS_FATAL("Failed to call service ModifyString");
    return 1;
  }

  return 0;
}
