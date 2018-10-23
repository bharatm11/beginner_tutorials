# beginner_tutorials


## Overview
This is a Programming Assignment for ENPM808X: Software Development for Robotics course to design a ROS Publisher and Subscriber from ROS Beginner Tutorials.

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
## Dependencies

ROS Kinetic
