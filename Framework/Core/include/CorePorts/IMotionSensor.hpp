#pragma once

#include "CoreModels/HardwareState.hpp"
#include "CoreModels/MotionState.hpp"
#include "CoreModels/SensorTypes.hpp"

namespace pad::framework::core {

class IMotionSensor
{
public:
   virtual bool read(MotionState& out_state, UpdateGroup group) = 0;
   virtual ~IMotionSensor() = default;
};

}  // namespace pad::framework::core