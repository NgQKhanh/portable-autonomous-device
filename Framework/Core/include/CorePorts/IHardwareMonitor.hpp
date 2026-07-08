#pragma once

#include "CoreModels/HardwareState.hpp"
#include "CoreModels/SensorTypes.hpp"

namespace pad::framework::core {

class IHardwareMonitor
{
public:
   virtual bool read(HardwareState& out_state, UpdateGroup group) = 0;
   virtual ~IHardwareMonitor() = default;
};

}  // namespace pad::framework::core