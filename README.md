# beginner_tutorials

branch:Week10_HW



## Overview
This is a Programming Assignment for ENPM808X: Software Development for Robotics course.
This ROS package demonstrates a node publishing a message to a topic and a node subscribing to that message. In addition to this, a service was added to the publisher node to change the published message.

## Build and install the package

```
#Make catkin workspace
mkdir -p catkin_ws/src
cd ~/catkin_ws
#Initialize catkin workspace
catkin_make 
cd src/
#Clone package
git clone https://github.com/bharatm11/beginner_tutorials
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
## Running roslaunch

```
roslaunch beginner_tutorials beginner_tutorial.launch freq:=15
```
where freq is a argument of publisher frequency

## Running the Service

Make sure the talker has been launched, then enter run service with value of num as 3 or anything else
```
rosservice call /ChangeString "num: 3"
```
or
```
rosservice call /ChangeString "num: 2"
```
to change the message published by talker.

## Dependencies

ROS Kinetic
