#include <memory>
#include <csignal>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

rclcpp::Node::SharedPtr node;

void sub_callback(const std_msgs::msg::String::SharedPtr msg){
  RCLCPP_INFO(node->get_logger(), "sub: '%s'", msg->data.c_str());
}

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  node = rclcpp::Node::make_shared("sub");
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub = node->create_subscription<std_msgs::msg::String>("topic", 10, sub_callback);
  rclcpp::spin(node);
  node.reset();
  rclcpp::shutdown();
  return 0;
}