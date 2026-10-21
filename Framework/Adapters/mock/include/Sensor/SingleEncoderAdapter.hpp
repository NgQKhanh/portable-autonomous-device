#pragma once

#include "Core/Model/SensorData.hpp"
#include "Core/Sensor/ISensor.hpp"

namespace pad::framework::adapter {

class SingleEncoderAdapter : public pad::framework::core::ISensor<pad::framework::core::WheelsVelocity>
{
public:
   core::SensorResult<core::WheelsVelocity> read() override;
};

}  // namespace pad::framework::adapter