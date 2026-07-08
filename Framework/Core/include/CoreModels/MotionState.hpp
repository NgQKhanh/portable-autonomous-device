#pragma once

#include <cstdint>

#include "CoreModels/ControlTypes.hpp"
#include "CoreModels/Kinematics.hpp"

namespace pad::framework::core {

struct MotionState
{
   Velocity2D currentVelocity;
   Pose2D currentPose;
};

}  // namespace pad::framework::core