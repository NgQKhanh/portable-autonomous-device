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
   //---------------- Motion ----------------
#ifdef CONFIG_DIFFERENTIAL_2WD
   LEFT_WHEEL_ENCODER,
   RIGHT_WHEEL_ENCODER,
   LEFT_MOTOR,
   RIGHT_MOTOR,
#endif

   //---------------- Environment ----------------
#ifdef CONFIG_LIDAR_2D
   LIDAR_2D,
#endif

   //---------------- Safety ----------------
   BUMPER_SENSOR,
   BATTERY_MONITOR,
   BUZZER,
   EMERGENCY_BUTTON,

   DEVICE_COUNT
};

}  // namespace pad::framework::core