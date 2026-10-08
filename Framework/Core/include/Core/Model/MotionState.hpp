#pragma once

#include <cstdint>

#include "Core/Model/Common.hpp"

namespace pad::framework::core {

struct Pose2D
{
   float theta = 0.0f;  // Heading angle (rad)
   float x = 0.0f;      // X position (m)
   float y = 0.0f;      // Y position (m)
};

struct Velocity2D
{
   float linear = 0.0f;   // Linear velocit (m/s)
   float angular = 0.0f;  // Angular velocity (rad/s)
};

struct MotionState
{
   Velocity2D currentVelocity;
   Pose2D currentPose;
};

}  // namespace pad::framework::core