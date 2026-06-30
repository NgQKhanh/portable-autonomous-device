#pragma once

#include "EnvironmentState.hpp"
#include "HardwareState.hpp"
#include "MotionState.hpp"

namespace pad::framework::domain {

struct SystemState
{
   HardwareState hardwareState;        // Hardware status of the device: battery level, sensor status, etc.
   EnvironmentState environmentState;  // Surrounding environment status: obstacles, cliffs, temperature, etc.
   MotionState motionState;            // Device motion status: speed, tilt angle, etc.
};

}  // namespace pad::framework::domain