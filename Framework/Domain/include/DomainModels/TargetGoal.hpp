#pragma once

#include <cstdint>

#include "DomainModels/ControlFlags.hpp"
#include "DomainModels/Kinematics.hpp"

namespace pad::framework::domain {

struct MotionTarget
{
   Velocity2D targetVelocity;
};

struct LightTarget
{
};

struct TargetGoal
{
   uint32_t targetMask = ControlMask::NONE;

   MotionTarget motion;
   LightTarget light;
};

}  // namespace pad::framework::domain