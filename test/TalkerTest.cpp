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
* @file TalkerTest.cpp
*  @brief TalkerTest.cpp is a test node that tests the talker node's service.
*
*  @author Bharat Mathur (bharatm11)
*  @bug No known bugs.
*  @copyright BSD License.
*/
#include <gtest/gtest.h>
#include <ros/console.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/ModifyString.h"

/** @brief TEST(TalkerTest, ChangeString) will
* test the ModifyString service of the talker node*/
TEST(TalkerTest, ModifyString) {
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::ModifyString>(
    "ModifyString");
    beginner_tutorials::ModifyString srv;
    srv.request.num = 1;
    client.call(srv);
    std::string m;
    m = "Now change to: Bharat";
    EXPECT_STREQ(m.c_str(), srv.response.name.c_str());
  }

  int main(int argc, char **argv) {
    ros::init(argc, argv, "testnode");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }
