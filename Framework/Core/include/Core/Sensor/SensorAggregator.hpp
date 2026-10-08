#pragma once

#include "Core/Algorithm/Kinematics/IKinematics.hpp"
#include "Core/Model/Device.hpp"
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

   bool validateStatus(DeviceId id, DeviceStatus status);
   bool validate(const BatteryData& data);
   bool validate(const Lidar2DData& data);

   WheelsVelocity getWheelsVelocity() const;
   Velocity2D getVelocity2D() const;

private:
   ISensor<WheelsVelocity>& m_wheels;
   ISensor<Lidar2DData>& m_lidar;
   ISensor<BatteryData>& m_battery;
   ISensor<CollisionData>& m_collision;

   IKinematics& m_kinematics;
   SystemState m_systemState{};
};

}  // namespace pad::framework::core