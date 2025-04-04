#pragma once

#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

#include <cost_map_interface/cost_map_interface.hpp>
#include <geometry_msgs/msg/point_stamped.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <list>
#include <nav_msgs/msg/path.hpp>
#include <pluginlib/class_loader.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/range.hpp>
#include <std_msgs/msg/bool.hpp>
#include <std_msgs/msg/float32.hpp>
#include <std_msgs/msg/int32.hpp>
#include <string>
#include <trajectory_library/trajectory_library.hpp>
#include <vector>
#include <visualization_msgs/msg/marker.hpp>
#include <visualization_msgs/msg/marker_array.hpp>

using std::placeholders::_1;

class ViewpointPlanner : public rclcpp::Node {
    private:
    public:
    ViewpointPlanner()
        : Node("viewpoint_planner") {
        RCLCPP_INFO(this->get_logger(), "Viewpoint Planner Node Initialized");
        // Initialize parameters, subscriptions, and publishers here
    }
    void initialize() {
        
    }
};
