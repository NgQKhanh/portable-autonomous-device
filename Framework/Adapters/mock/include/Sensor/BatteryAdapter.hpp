#pragma once

#include "Core/Model/SensorData.hpp"
#include "Core/Sensor/ISensor.hpp"

namespace pad::framework::adapter {

class BatteryAdapter : public pad::framework::core::ISensor<pad::framework::core::BatteryData>
{
public:
   core::SensorResult<core::BatteryData> read() override;
};

}  // namespace pad::framework::adapter