#pragma once

#include "Core/Algorithm/Kinematics/IKinematics.hpp"

namespace pad::framework::core {

struct DifferentialDriveConfig
{
   float wheelRadius{};
   float wheelSeparation{};
};

class DifferentialDriveKinematics : public IKinematics
{
public:
   explicit DifferentialDriveKinematics(const DifferentialDriveConfig& config);
   Velocity2D calculate(const WheelsVelocity& wheelsVelocity) override;
};

}  // namespace pad::framework::core