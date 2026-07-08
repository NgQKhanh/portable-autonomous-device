#pragma once

#include "CoreModels/EnvironmentState.hpp"
#include "CoreModels/HardwareState.hpp"
#include "CoreModels/SensorTypes.hpp"

namespace pad::framework::core {

class ISurroundingsSensor
{
public:
   virtual bool read(EnvironmentState& out_state, UpdateGroup group) = 0;
   virtual ~ISurroundingsSensor() = default;
};

}  // namespace pad::framework::core