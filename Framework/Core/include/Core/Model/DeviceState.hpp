#pragma once

#include <cstdint>

#include "Core/Model/Common.hpp"
#include "Core/Model/Device.hpp"
#include "Core/Model/SensorData.hpp"

namespace pad::framework::core {

struct DeviceState
{
   BatteryData powerState;
   DeviceStatus devices[DEVICE_COUNT];
};

}  // namespace pad::framework::core