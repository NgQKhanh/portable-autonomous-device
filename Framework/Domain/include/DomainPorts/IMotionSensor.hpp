#pragma once

#include "DomainModels/HardwareState.hpp"
#include "DomainModels/MotionState.hpp"
#include "DomainModels/SensorTypes.hpp"

namespace pad::framework::domain {

class IMotionSensor
{
public:
   virtual bool read(MotionState& out_state, UpdateGroup group) = 0;
   virtual ~IMotionSensor() = default;
};

}  // namespace pad::framework::domain