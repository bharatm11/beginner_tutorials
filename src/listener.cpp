// "Copyright [2018] <Bharat Mathur>"
/** @file listener.cpp
  *  @brief listener.cpp is a node subscribes to a string msg on chatter topic
  *
  *  @author Bharat Mathur (bharatm11)
  *  @bug No known bugs.
  *  @copyright GNU Public License.
*/
#include "ros/ros.h"
#include "std_msgs/String.h"

/**@brief This function is a callback function to output a msg content
  * @param[in] msg is a message type
  * @return none
*/
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  ROS_DEBUG("Starting subscriber");
  ros::spin();
  return 0;
}
