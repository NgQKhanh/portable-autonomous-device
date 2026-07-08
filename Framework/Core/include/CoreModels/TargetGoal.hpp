#pragma once

#include <cstdint>

#include "CoreModels/ControlTypes.hpp"
#include "CoreModels/Kinematics.hpp"

namespace pad::framework::core {

struct MotionTarget
{
   Velocity2D targetVelocity;
};

struct LightTarget
{
};

struct TargetGoal
{
   ControlMask targetMask = ControlMask::NONE;

   MotionTarget motion;
   LightTarget light;
};

}  // namespace pad::framework::core