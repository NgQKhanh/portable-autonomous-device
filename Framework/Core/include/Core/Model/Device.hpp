#pragma once

#include <cstdint>

namespace pad::framework::core {

enum class DeviceStatus : uint8_t
{
   OK = 0,
   ERROR,
   TIMEOUT,
   DISCONNECTED,
   NOT_SUPPORTED
};
enum DeviceId
{
   NONE,
   //---------------- Sensors ----------------
   LEFT_WHEEL_ENCODER,
   RIGHT_WHEEL_ENCODER,
   LIDAR_2D,
   IMU_SENSOR,
   BUMPER_SENSOR,
   BATTERY_MONITOR,

   //---------------- Actuators ---------------
   LEFT_MOTOR,
   RIGHT_MOTOR,

   //---------------- Interaction -------------
   BUZZER,
   EMERGENCY_BUTTON,

   DEVICE_COUNT
};

}  // namespace pad::framework::core