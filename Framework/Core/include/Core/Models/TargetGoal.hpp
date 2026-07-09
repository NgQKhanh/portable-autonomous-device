#pragma once

#include <cstdint>

#include "Core/Models/ControlTypes.hpp"
#include "Core/Models/Kinematics.hpp"

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