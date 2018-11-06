// "Copyright [2018] <Bharat Mathur>"
/** @file talker.cpp
  *  @brief talker.cpp is a node publishes a string to chatter topic
  *
  *  @author Bharat Mathur (bharatm11)
  *  @bug No known bugs.
  *  @copyright GNU Public License.
*/
#include <ros/console.h>
#include <sstream>
#include "std_msgs/String.h"
#include "ros/ros.h"
#include "beginner_tutorials/ModifyString.h"

std::stringstream ss;
int freqRate = 20;

/**@brief This function is a callback function to change the output string.
  * @param[in] &req is the ROS service request.
  * @param[out] &res is a ROS service response.
  * @return bool
*/
bool change(beginner_tutorials::ModifyString::Request  &req,
  beginner_tutorials::ModifyString::Response &res) {
    ss.str(" ");
    if (req.num == 1) {
      res.name = "Now change to: Bharat";
      ss<< " Bharat ";
    } else {
      res.name = "Now change to: Bharat Mathur 007";
      ss<< " Bharat Mathur 007 ";
    }
    return true;
  }


  int main(int argc, char **argv) {
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    n.getParam("freq" , freqRate);
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::ServiceServer service = n.advertiseService("ModifyString", change);
    ros::Rate loop_rate(freqRate);
    ROS_WARN("Default freq of 20Hz will be used if freq is not passed");
    int count = 0;
    if (ros::ok()) {
      while (ros::ok()) {
        std_msgs::String msg;
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());
        ROS_DEBUG("Publishing msgs");
        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
      }
    } else {
      ROS_FATAL("Talker not initialized");
    }
    return 0;
  }
