#include<ros/ros.h>
#include<tf/transform_broadcaster.h>

std::string frame_name = "talk";

int main(int argc, char ** argv){

	ros::init(argc, argv, "frame_broadcaster");
	ros::NodeHandle nh_frame_broadcaster;
	int loop_freq = 100;
	float dt = (float) 1/loop_freq;
	ros::Rate loop_rate(loop_freq);
	static tf::TransformBroadcaster br;
	tf::Transform transform;
	transform.setOrigin(tf::Vector3(0, 0, 0.04));
	tf::Quaternion q;
	q.setRPY(0,0,M_PI);
	transform.setRotation(q);

	while(ros::ok()){

		br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), frame_name, "world"));
		loop_rate.sleep();
		ros::spinOnce();
	}



	return 0;
}
