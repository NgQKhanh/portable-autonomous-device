#pragma once

#include "Core/Model/MotionState.hpp"
#include "Core/Model/SensorData.hpp"

namespace pad::framework::core {

class IKinematics
{
public:
   virtual Velocity2D calculate(const WheelsVelocity& wheelsVelocity) = 0;
   virtual ~IKinematics() = default;
};

}  // namespace pad::framework::core