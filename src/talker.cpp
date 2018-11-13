/**
* BSD 3-Clause LICENSE
*
* Copyright (c) 2018, Bharat Mathur
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*
* 1. Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
*
* 3. Neither the name of the copyright holder nor the names of its
* contributors may be used to endorse or promote products derived from this
* software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
* IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
* CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.

/**
* @file talker.cpp
*  @brief talker.cpp is a node publishes a string to chatter topic
*  @author Bharat Mathur (bharatm11)
*  @bug No known bugs.
*  @copyright BSD License.
*/

#include <ros/console.h>
#include<tf/transform_broadcaster.h>
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
bool change(beginner_tutorials::ModifyString::Request &req,
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

    static tf::TransformBroadcaster br;
    tf::Transform transform;
    transform.setOrigin(tf::Vector3(0, 0, 0.04));
    tf::Quaternion q;
    q.setRPY(0, 0, M_PI);
    transform.setRotation(q);
    std::string frame_name = "talk";

    if (ros::ok()) {
      while (ros::ok()) {
        std_msgs::String msg;
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());
        ROS_DEBUG("Publishing msgs");
        chatter_pub.publish(msg);
        br.sendTransform(tf::StampedTransform(transform, ros::Time::now(),
                                                          frame_name, "world"));
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
      }
    } else {
      ROS_FATAL("Talker not initialized");
    }
    return 0;
  }
