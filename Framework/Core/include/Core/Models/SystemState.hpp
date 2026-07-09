#pragma once

#include "Core/Models/EnvironmentState.hpp"
#include "Core/Models/HardwareState.hpp"
#include "Core/Models/MotionState.hpp"

namespace pad::framework::core {

struct SystemState
{
   HardwareState hardwareState;        // Hardware status of the device: battery level, sensor status, etc.
   EnvironmentState environmentState;  // Surrounding environment status: obstacles, cliffs, temperature, etc.
   MotionState motionState;            // Device motion status: speed, tilt angle, etc.
};

}  // namespace pad::framework::core