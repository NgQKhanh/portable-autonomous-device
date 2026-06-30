#pragma once

#include "DomainModels/EnvironmentState.hpp"
#include "DomainModels/HardwareState.hpp"
#include "DomainModels/MotionState.hpp"

namespace pad::framework::domain {

struct SystemState
{
   HardwareState hardwareState;        // Hardware status of the device: battery level, sensor status, etc.
   EnvironmentState environmentState;  // Surrounding environment status: obstacles, cliffs, temperature, etc.
   MotionState motionState;            // Device motion status: speed, tilt angle, etc.
};

}  // namespace pad::framework::domain