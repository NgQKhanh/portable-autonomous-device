#pragma once

#include "Core/Models/HardwareState.hpp"
#include "Core/Models/MotionState.hpp"
#include "Core/Models/SensorTypes.hpp"

namespace pad::framework::core {

class IMotionSensor
{
public:
   virtual bool read(MotionState& out_state, UpdateGroup group) = 0;
   virtual ~IMotionSensor() = default;
};

}  // namespace pad::framework::core