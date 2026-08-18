#pragma once

#include <cstdint>

#include "Core/Model/DeviceState.hpp"
#include "Core/Model/EnvironmentState.hpp"
#include "Core/Model/MotionState.hpp"

namespace pad::framework::core {

struct SystemState
{
   DeviceState deviceState;
   EnvironmentState environmentState;
   MotionState motionState;
};

}  // namespace pad::framework::core