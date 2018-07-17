#include "ros/ros.h"
#include "std_msgs/Float64.h"

double status = 0.;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "output");
  ros::NodeHandle n;
  n.param<double>("data", status, 10.);
  ros::Publisher chatter_pub = n.advertise<std_msgs::Float64>("output", 1000);
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
