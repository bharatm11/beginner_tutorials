#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/ModifyString.h"

std::stringstream ss;
int freqRate=20;

bool change(beginner_tutorials::ModifyString::Request  &req,
  beginner_tutorials::ModifyString::Response &res) {
    ss.str(" ");
    if(req.num==1) {
      res.name="Now change to: Bharat";
      ss<< " Bharat ";
    }
    else {
      res.name="Now change to: Bharat Mathur 007";
      ss<< " Bharat Mathur 007 ";
    }
    return true;
  }


  int main(int argc, char **argv) {

    ros::init(argc, argv, "talker");

    ros::NodeHandle n;
    n.getParam("freq",freqRate);

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    ros::ServiceServer service = n.advertiseService("ModifyString", change);

    ros::Rate loop_rate(freqRate);

    int count = 0;

    while (ros::ok()) {

      std_msgs::String msg;
      msg.data = ss.str();

      ROS_INFO("%s", msg.data.c_str());

      chatter_pub.publish(msg);

      ros::spinOnce();

      loop_rate.sleep();
      ++count;
    }

    return 0;
  }
