#pragma once

#include "Core/Algorithm/Kinematics/IKinematics.hpp"
#include "Core/Algorithm/Lidar/ConvertToPointCloud.hpp"
#include "Core/Model/SensorData.hpp"
#include "Core/Model/SystemState.hpp"
#include "Core/Sensor/ISensor.hpp"

namespace pad::framework::core {

struct SensorDependencies
{
   ISensor<WheelsVelocity>& wheels;
   ISensor<Lidar2DData>& lidar;
   ISensor<BatteryData>& battery;
   ISensor<CollisionData>& collision;
   IKinematics& kinematics;
};

class SensorAggregator
{
public:
   explicit SensorAggregator(const SensorDependencies& dependencies);
   ~SensorAggregator();

   bool isTimestampValid(Timestamp timestamp) const;

   SystemState getSystemState() const;

   PowerState getPowerState() const;
   bool updateBatteryData();

   WheelsVelocity getWheelsVelocity() const;
   bool updateWheelsVelocity();
   Velocity2D getVelocity2D() const;
   void estimateVelocity2D();

   Lidar2DData getLidar2DData() const;
   bool updateLidar2DData();
   PointCloud getPointCloud() const;
   void convertToPointCloud();

private:
   ISensor<WheelsVelocity>& m_wheels;
   ISensor<Lidar2DData>& m_lidar;
   ISensor<BatteryData>& m_battery;
   ISensor<CollisionData>& m_collision;

   IKinematics& m_kinematics;

   SystemState m_systemState{};
   WheelsVelocity m_wheelsVelocity{};
   PointCloud m_pointCloud{};
   Lidar2DData m_lidar2DData{};
};

}  // namespace pad::framework::core