#pragma once

#include "DomainModels/EnvironmentState.hpp"
#include "DomainModels/HardwareState.hpp"
#include "DomainModels/SensorTypes.hpp"

namespace pad::framework::domain {

class ISurroundingsSensor
{
public:
   virtual bool read(EnvironmentState& out_state, UpdateGroup group) = 0;
   virtual ~ISurroundingsSensor() = default;
};

}  // namespace pad::framework::domain