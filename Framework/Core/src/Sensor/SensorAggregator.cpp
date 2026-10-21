#include "Core/Sensor/SensorAggregator.hpp"

#include "Infrastructure/Logging/Log.hpp"

namespace pad::framework::core {

SensorAggregator::SensorAggregator(const SensorDependencies& dependencies)
    : m_wheels(dependencies.wheels),
      m_lidar(dependencies.lidar),
      m_battery(dependencies.battery),
      m_collision(dependencies.collision),
      m_kinematics(dependencies.kinematics)
{
}

bool SensorAggregator::validateStatus(DeviceId id, DeviceStatus status)
{
   if (status != DeviceStatus::OK)
   {
      LOG_ERR("Validate device status failed - id: %d, status: %d", static_cast<int>(id), static_cast<int>(status));
      // TODO: process not ok status
      return false;
   }
   return true;
}

}  // namespace pad::framework::core