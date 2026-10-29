#include <gtest/gtest.h>

#include "Core/Algorithm/Kinematics/DifferentialDriveKinematics.hpp"

namespace pad::framework::core {
namespace {

constexpr float FLOAT_TOLERANCE = 1e-5f;

// ============================================================
// Velocity2D calculate(const WheelsVelocity& wheelsVelocity)
// ============================================================

TEST(TestDifferentialDriveKinematics, CalculateVelocity_ValidInput_ReturnsExpectedValue)
{
   WheelsVelocity input;                         // {timestamp, [WHEEL_LEFT, WHEEL_RIGHT]}}
   DifferentialDriveConfig config{0.05f, 0.3f};  // Assume radius of wheels is 0.05m and distance between wheels is 0.3m.
   const DifferentialDriveKinematics kinematics(config);

   // Case 1: wheels moving at same speed -> moving forward.
   {
      input = {0, {2.0f, 2.0f}};
      const auto result = kinematics.calculate(input);

      EXPECT_NEAR(result.linear, 0.1f, FLOAT_TOLERANCE) << "FAILED: Case 1 - Linear velocity mismatch";
      EXPECT_NEAR(result.angular, 0.0f, FLOAT_TOLERANCE) << "FAILED: Case 1 - Angular velocity mismatch";
   }

   // Case 2: wheels moving at opposite speeds -> rotating in place.
   {
      input = {0, {-2.0f, 2.0f}};
      const auto result = kinematics.calculate(input);

      EXPECT_NEAR(result.linear, 0.0f, FLOAT_TOLERANCE) << "FAILED: Case 2 - Linear velocity mismatch";
      EXPECT_NEAR(result.angular, 2.0f / 3.0f, FLOAT_TOLERANCE) << "FAILED: Case 2 - Angular velocity mismatch";
   }

   // Case 3: wheels moving at different speeds.
   {
      input = {0, {2.0f, 4.0f}};
      const auto result = kinematics.calculate(input);

      EXPECT_NEAR(result.linear, 0.15f, FLOAT_TOLERANCE) << "FAILED: Case 3 - Linear velocity mismatch";
      EXPECT_NEAR(result.angular, 1.0f / 3.0f, FLOAT_TOLERANCE) << "FAILED: Case 3 - Angular velocity mismatch";
   }

   // Case 4: Both wheels at rest.
   {
      input = {0, {0.0f, 0.0f}};
      const auto result = kinematics.calculate(input);

      EXPECT_NEAR(result.linear, 0.0f, FLOAT_TOLERANCE) << "FAILED: Case 4 - Linear velocity mismatch";
      EXPECT_NEAR(result.angular, 0.0f, FLOAT_TOLERANCE) << "FAILED: Case 4 - Angular velocity mismatch";
   }
}

}  // namespace
}  // namespace pad::framework::core