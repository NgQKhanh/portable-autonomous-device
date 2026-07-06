#pragma once

#include <cstdint>

#include "DomainModels/ControlTypes.hpp"
#include "DomainModels/Kinematics.hpp"

namespace pad::framework::domain {

struct MotionState
{
   Velocity2D currentVelocity;
   Pose2D currentPose;
};

}  // namespace pad::framework::domain