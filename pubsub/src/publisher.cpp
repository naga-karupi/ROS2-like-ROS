#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::Node::SharedPtr node = rclcpp::Node::make_shared("pub");
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub = node->create_publisher<std_msgs::msg::String>("topic", 10);
  rclcpp::Rate rate(10);

  auto msg = std_msgs::msg::String();

  while (rclcpp::ok()) {
    msg.data = "hello world";
    RCLCPP_INFO(node->get_logger(), "Pub: '%s'", msg.data.c_str());
    pub->publish(msg);
    rclcpp::spin_some(node);
   
    rate.sleep();
  }
  return 0;
}