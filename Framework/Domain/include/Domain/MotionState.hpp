#pragma once

#include <cstdint>

#include "ControlFlags.hpp"
#include "Kinematics.hpp"

namespace pad::framework::domain {

struct MotionState
{
   Velocity2D currentVelocity;
   Pose2D currentPose;
};

}  // namespace pad::framework::domain