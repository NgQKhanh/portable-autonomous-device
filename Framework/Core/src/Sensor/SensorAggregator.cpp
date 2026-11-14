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

bool SensorAggregator::isTimestampValid(Timestamp timestamp) const
{
   // TODO: Implementation for timestamp validation
   return true;
}

SystemState SensorAggregator::getSystemState() const
{
   return m_systemState;
}

PowerState SensorAggregator::getPowerState() const
{
   return m_systemState.deviceState.powerState;
}

bool SensorAggregator::updateBatteryData()
{
   SensorResult<BatteryData> result = m_battery.read();
   if (result.status != DeviceStatus::OK)
   {
      LOG_ERR("Failed to read battery data");
      return false;
   }
   if (!isTimestampValid(result.data.timestamp))
   {
      LOG_ERR("Invalid timestamp for battery data");
      return false;
   }
   m_systemState.deviceState.powerState.battery = result.data;
   return true;
}

WheelsVelocity SensorAggregator::getWheelsVelocity() const
{
   return m_wheelsVelocity;
}

bool SensorAggregator::updateWheelsVelocity()
{
   SensorResult<WheelsVelocity> result = m_wheels.read();
   if (result.status != DeviceStatus::OK)
   {
      LOG_ERR("Failed to read wheels velocity");
      return false;
   }
   if (!isTimestampValid(result.data.timestamp))
   {
      LOG_ERR("Invalid timestamp for wheels velocity");
      return false;
   }
   m_wheelsVelocity = result.data;
   return true;
}

Velocity2D SensorAggregator::getVelocity2D() const
{
   return m_systemState.motionState.currentVelocity;
}

void SensorAggregator::estimateVelocity2D()
{
   m_systemState.motionState.currentVelocity = m_kinematics.calculate(getWheelsVelocity());
}

Lidar2DData SensorAggregator::getLidar2DData() const
{
   return m_lidar2DData;
}

bool SensorAggregator::updateLidar2DData()
{
   SensorResult<Lidar2DData> result = m_lidar.read();
   if (result.status != DeviceStatus::OK)
   {
      LOG_ERR("Failed to read LIDAR data");
      return false;
   }
   if (!isTimestampValid(result.data.timestamp))
   {
      LOG_ERR("Invalid timestamp for LIDAR data");
      return false;
   }
   m_lidar2DData = result.data;
   return true;
}

PointCloud SensorAggregator::getPointCloud() const
{
   return m_systemState.environmentState.pointCloud;
}

void SensorAggregator::convertToPointCloud()
{
   m_systemState.environmentState.pointCloud = PointCloudConverter().convertToPointCloud2D(m_lidar2DData);
}

}  // namespace pad::framework::core