#pragma once

#include <cstdint>

namespace pad::framework::core {

enum class SystemFaultFlag : uint32_t
{
   FAULT_NONE = 0,
   FAULT_EMERGENCY_STOP = (1 << 0),    // Emergency stop command from hardware
   FAULT_CLIFF_DETECTED = (1 << 1),    // Risk of falling off an edge
   FAULT_MOTOR_STALLED = (1 << 2),     // Motor overcurrent or wheel stall
   FAULT_LOW_BATTERY = (1 << 3),       // Battery level below the safe threshold
   FAULT_SENSOR_DISCONNECT = (1 << 4)  // Lost I2C/SPI communication with a sensor
};

struct SystemEvent
{
   uint32_t activeFaults;  // Bit mask of all currently active faults
};

}  // namespace pad::framework::core