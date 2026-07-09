#pragma once

#include "Core/Models/EnvironmentState.hpp"
#include "Core/Models/HardwareState.hpp"
#include "Core/Models/SensorTypes.hpp"

namespace pad::framework::core {

class ISurroundingsSensor
{
public:
   virtual bool read(EnvironmentState& out_state, UpdateGroup group) = 0;
   virtual ~ISurroundingsSensor() = default;
};

}  // namespace pad::framework::core