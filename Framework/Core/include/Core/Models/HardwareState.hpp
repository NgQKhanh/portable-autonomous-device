#pragma once

#include <cstdint>

namespace pad::framework::core {

// Dummy data
// TODO: using external config file to set sensor count
#define SENSOR_COUNT 10

enum class DeviceStatus : uint8_t
{
   OK = 0,
   WARNING,
   ERROR,
   DISCONNECTED,
   STATUS_CNT
};

struct HardwareState
{
   uint8_t batteryLevel;
   DeviceStatus deviceStatus[SENSOR_COUNT];
};

}  // namespace pad::framework::core