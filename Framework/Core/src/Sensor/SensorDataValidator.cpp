#include "Core/Sensor/SensorDataValidator.hpp"

#include <cmath>

#include "Infrastructure/Logging/Log.hpp"

namespace pad::framework::core {

bool SensorDataValidator::validateStatus(DeviceId id, DeviceStatus status)
{
   if (status != DeviceStatus::OK)
   {
      LOG_ERR("Validate device status failed - id: %d, status: %d", static_cast<int>(id), static_cast<int>(status));
      // TODO: process not ok status
      return false;
   }
   return true;
}

bool SensorDataValidator::validate(const BatteryData& data)
{
   if (!std::isfinite(data.voltage) || data.voltage > Constants::MAX_VOLTAGE || data.voltage < 0.0f)
      return false;

   if (!std::isfinite(data.current) || data.current > Constants::MAX_CURRENT)
      return false;

   if (data.percentage > 100)
      return false;

   return true;
}

bool SensorDataValidator::validate(const LidarData& data)
{
   if (!std::isfinite(data.angleMin) ||
       !std::isfinite(data.angleMax) ||
       !std::isfinite(data.angleIncrement))
   {
      return false;
   }

   if (data.angleMin < 0.0f || data.angleMin > Constants::FULL_CIRCLE_DEGREES ||
       data.angleMax < 0.0f || data.angleMax > Constants::FULL_CIRCLE_DEGREES ||
       data.angleIncrement <= 0.0f || data.angleIncrement > Constants::FULL_CIRCLE_DEGREES)
   {
      return false;
   }

   if (data.angleMin > data.angleMax)
   {
      return false;
   }

   for (uint16_t i = 0; i < MAX_SCAN_POINTS; i++)
   {
      if (!std::isfinite(data.ranges[i]))
      {
         LOG_ERR("Invalid LiDAR range - index: %zu, value: %f", i, data.ranges[i]);
         return false;
      }
   }

   return true;
}

}  // namespace pad::framework::core