#pragma once

#include <cstdint>

#include "Core/Models/ControlTypes.hpp"
#include "Core/Models/Kinematics.hpp"

namespace pad::framework::core {

struct MotionState
{
   Velocity2D currentVelocity;
   Pose2D currentPose;
};

}  // namespace pad::framework::core