#pragma once

#include "DomainModels/HardwareState.hpp"
#include "DomainModels/SensorTypes.hpp"

namespace pad::framework::domain {

class IHardwareMonitor
{
public:
   virtual bool read(HardwareState& out_state, UpdateGroup group) = 0;
   virtual ~IHardwareMonitor() = default;
};

}  // namespace pad::framework::domain