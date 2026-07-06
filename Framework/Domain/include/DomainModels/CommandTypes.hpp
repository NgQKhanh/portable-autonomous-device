#pragma once

#include <cstdint>

#include "DomainModels/ControlTypes.hpp"
#include "DomainModels/Kinematics.hpp"

namespace pad::framework::domain {

struct MotionCommand
{
   Velocity2D velocityCmd;
};

struct LightCommand
{
};

struct CommandBundle
{
   ControlMask cmdMask = ControlMask::NONE;

   MotionCommand motionCmd;
   LightCommand lightCmd;
};

}  // namespace pad::framework::domain