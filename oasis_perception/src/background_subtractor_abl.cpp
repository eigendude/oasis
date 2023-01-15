/*
 *  Copyright (C) 2021-2024 Garrett Brown
 *  This file is part of OASIS - https://github.com/eigendude/OASIS
 *
 *  SPDX-License-Identifier: Apache-2.0
 *  See the file LICENSE.txt for more information.
 */

#include "image/BackgroundModelerABL.h"
#include "image/MultiModeler.h"
#include "utils/NetworkUtils.h"

#include <memory>

#include <rclcpp/rclcpp.hpp>

using namespace OASIS;

namespace OASIS
{
constexpr const char* ROS_NAMESPACE = "oasis"; // TODO

constexpr const char* BGS_ABL_NODE_NAME = "background_substractor_abl";

// TODO: Hardware configuration
constexpr const char* VIDEO_MACHINE_ASUS = "asus";
constexpr const char* VIDEO_MACHINE_KINECT2 = "kinect2";
constexpr const char* VIDEO_MACHINE_LENOVO = "lenovo";

// Subscribed topics
constexpr const char* IMAGE_TOPIC_ASUS = "image_raw";
constexpr const char* IMAGE_TOPIC_KINECT2 = "hd/image_color";
constexpr const char* IMAGE_TOPIC_LENOVO = "image_raw";

// Published topics
constexpr const char* BACKGROUND_TOPIC = "background";
} // namespace OASIS

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);

  // Get the hostname
  const std::string appendHostname = "_" + OASIS::UTILS::NetworkUtils::GetHostName();

  // Create node
  std::shared_ptr<rclcpp::Node> node =
      std::make_shared<rclcpp::Node>(BGS_ABL_NODE_NAME + appendHostname);

  // Create topics
  const std::string topicBase = std::string("/") + ROS_NAMESPACE + "/" + VIDEO_MACHINE_LENOVO + "/";

  {
    OASIS::IMAGE::BackgroundModelerABL backgroundModeler(node, topicBase + IMAGE_TOPIC_LENOVO,
                                                         topicBase + BACKGROUND_TOPIC);

    rclcpp::spin(node);
  }

  rclcpp::shutdown();

  return 0;
}
