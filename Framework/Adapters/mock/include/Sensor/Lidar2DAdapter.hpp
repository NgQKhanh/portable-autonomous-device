#pragma once

#include "Core/Model/SensorData.hpp"
#include "Core/Sensor/ISensor.hpp"

namespace pad::framework::adapter {

class Lidar2DAdapter : public pad::framework::core::ISensor<pad::framework::core::Lidar2DData>
{
public:
   core::SensorResult<core::Lidar2DData> read() override;
};

}  // namespace pad::framework::adapter