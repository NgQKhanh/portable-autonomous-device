#pragma once

#include <cstdint>

#include "Core/Models/ControlTypes.hpp"
#include "Core/Models/Kinematics.hpp"

namespace pad::framework::core {

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

}  // namespace pad::framework::core