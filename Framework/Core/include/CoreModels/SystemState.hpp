#pragma once

#include "CoreModels/EnvironmentState.hpp"
#include "CoreModels/HardwareState.hpp"
#include "CoreModels/MotionState.hpp"

namespace pad::framework::core {

struct SystemState
{
   HardwareState hardwareState;        // Hardware status of the device: battery level, sensor status, etc.
   EnvironmentState environmentState;  // Surrounding environment status: obstacles, cliffs, temperature, etc.
   MotionState motionState;            // Device motion status: speed, tilt angle, etc.
};

}  // namespace pad::framework::core