#pragma once

#include "Core/Models/HardwareState.hpp"
#include "Core/Models/SensorTypes.hpp"

namespace pad::framework::core {

class IHardwareMonitor
{
public:
   virtual bool read(HardwareState& out_state, UpdateGroup group) = 0;
   virtual ~IHardwareMonitor() = default;
};

}  // namespace pad::framework::core