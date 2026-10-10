#include "Core/Algorithm/Kinematics/DifferentialDriveKinematics.hpp"

#include <cmath>

#include "Infrastructure/Utilities/Assert.hpp"

namespace pad::framework::core {

DifferentialDriveKinematics::DifferentialDriveKinematics(const DifferentialDriveConfig& config)
    : m_config(config)
{
   const bool isConfigValid = std::isfinite(config.wheelRadius) &&
                              config.wheelRadius > 0.0f &&
                              std::isfinite(config.wheelSeparation) &&
                              config.wheelSeparation > 0.0f;

   PAD_FATAL_MSG(isConfigValid, "Invalid differential drive configuration!");
}

Velocity2D DifferentialDriveKinematics::calculate(const WheelsVelocity& wheelsVelocity) const
{
   const float v_left = wheelsVelocity.velocities[Wheel::LEFT] * m_config.wheelRadius;
   const float v_right = wheelsVelocity.velocities[Wheel::RIGHT] * m_config.wheelRadius;

   Velocity2D velocity{};
   velocity.linear = (v_left + v_right) / 2.0f;
   velocity.angular = (v_right - v_left) / m_config.wheelSeparation;

   return velocity;
}

}  // namespace pad::framework::core