#pragma once

#include "Core/Model/Device.hpp"
#include "Core/Model/SensorData.hpp"
#include "Core/Sensor/ISensor.hpp"

namespace pad::framework::core {

// Define constants
// TODO: using config file
namespace Constants {

constexpr float MAX_VOLTAGE = 100.0f;
constexpr float MAX_CURRENT = 100.0f;
constexpr float FULL_CIRCLE_DEGREES = 360.0f;

}  // namespace Constants

class SensorDataValidator
{
public:
   bool validateStatus(DeviceId id, DeviceStatus status);
   bool validate(const BatteryData& data);
   bool validate(const LidarData& data);
};

}  // namespace pad::framework::core