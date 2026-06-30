#pragma once

#include <cstdint>

#include "DomainModels/Kinematics.hpp"

namespace pad::framework::domain {

struct MotionCommand
{
   Velocity2D velocityCmd;
};

}  // namespace pad::framework::domain