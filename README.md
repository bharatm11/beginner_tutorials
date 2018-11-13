
# beginner_tutorials

branch:Week11_HW

[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)


## Overview
This is a Programming Assignment for ENPM808X: Software Development for Robotics course.
This ROS package demonstrates a node publishing a message to a topic and a node subscribing to that message. In addition to this, a service was added to the publisher node to change the published message. A static TF broadcaster was implemented. ROSTests for the service were written. Data of all topics was recorded using rosbag.

## Build and install the package

```
#Make catkin workspace
mkdir -p catkin_ws/src
cd ~/catkin_ws
#Initialize catkin workspace
catkin_make 
cd src/
#Clone package
git clone --recursive https://github.com/bharatm11/beginner_tutorials
cd beginner_tutorials
git checkout Week11_HW
cd ..
cd ..
#Build Workspace
catkin_make 
```

## Running the package

Source the workspace
```
cd ~/catkin_ws
source devel/setup.bash
```
Open a terminal and type: 
```
roscore
```
This starts a rosmaster. 

Now, open a new terminal and type:
```
rosrun beginner_tutorials talker
``` 
This starts the publisher.

Lastly, open a new terminal and type:
```
rosrun beginner_tutorials listener
```
This starts the subscriber. 

To listen to the published topic, open a new terminal and type:
```
rostopic echo /chatter 

```

To listen to the broadcasted tf, open a new terminal and type:
```
rosrun tf tf_echo talk world

```

Moreover, you can use
```
rosrun tf view_frames
```
to see the relation between two frames.


## Running roslaunch

To execute all nodes while recording the rosbag file, type:
```
roslaunch beginner_tutorials beginner_tutorial.launch freq:=15 record:=1
```

To execute all nodes without recording the rosbag file, type:
```
roslaunch beginner_tutorials beginner_tutorial.launch freq:=15 record:=0
```
where freq is the argument of publisher frequency

## Running the Service

Make sure the talker has been launched, then enter run service with value of num as 1 or anything else
```
rosservice call /ModifyString "num: 1"
```
or
```
rosservice call /ModifyString "num: 2"
```
to change the message published by talker.

## ROSTest

To run ROSTests, type:
```
cd ~/catkin_ws
catkin_make run_tests
rostest beginner_tutorials beginner_tutorials_Test.launch
```
## Rosbag

Rosbag file created when nodes are launched with record argument equals 1 can be played using the following commands:

```
cd catkin_ws/src/beginner_tutorials/
rosbag play myrosbag_2018-11-12-21-19-51
```
Note: The name of the rosbag file can be different.

The recorded rosbag file can be verified by executing the listener node or echoing the tf topic using the following commands:

```
rosrun beginner_tutorials listener
```

or

```
rosrun tf tf_echo talk world

```


## Dependencies

ROS Kinetic
