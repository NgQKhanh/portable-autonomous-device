#pragma once

namespace pad::framework::core {

struct Pose2D
{
   float theta;  // Heading angle (rad)
   float pos_x;  // X position (m)
   float pos_y;  // Y position (m)
};

struct Velocity2D
{
   float linear;   // Linear velocit v (m/s)
   float angular;  // Angular velocity ω (rad/s)
};

}  // namespace pad::framework::core