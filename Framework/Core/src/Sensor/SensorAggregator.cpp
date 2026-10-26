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

WheelsVelocity SensorAggregator::getWheelsVelocity() const
{
   SensorResult<WheelsVelocity> result = m_wheels.read();
   if (result.status != DeviceStatus::OK)
   {
      LOG_ERR("Failed to read wheels velocity");
      return {};
   }
   return result.data;
}

Velocity2D SensorAggregator::getVelocity2D() const
{
   return m_systemState.motionState.currentVelocity;
}

void SensorAggregator::estimateVelocity2D()
{
   m_systemState.motionState.currentVelocity = m_kinematics.calculate(getWheelsVelocity());
}

}  // namespace pad::framework::core