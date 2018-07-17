#include "ros/ros.h"
#include "std_msgs/Float64.h"

double status = 0.;

void callback(const std_msgs::Float64::ConstPtr& msg) {
	status = 0.9*status + 0.1*msg->data;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "triple_input");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::Float64>("output", 1000);
  ros::Subscriber sub1 = n.subscribe("input1", 1000, callback);
  ros::Subscriber sub2 = n.subscribe("input2", 1000, callback);
  ros::Subscriber sub3 = n.subscribe("input3", 1000, callback);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    std_msgs::Float64 msg;
    msg.data = status;

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }
  return 0;
}
