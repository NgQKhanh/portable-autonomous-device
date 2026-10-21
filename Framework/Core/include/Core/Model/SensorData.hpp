#pragma once

#include <cstdint>

#include "Core/Model/Common.hpp"
#include "PadParameters.hpp"

namespace pad::framework::core {

// ------------------------------------------------------------------------------------------------
// Power data and electrical metrics of the system
// ------------------------------------------------------------------------------------------------
struct BatteryData
{
   Timestamp timestamp{};
   float voltage = 0.0f;    // V
   float current = 0.0f;    // A
   uint8_t percentage = 0;  // 0 - 100%
   bool isCharging = false;
};

// ------------------------------------------------------------------------------------------------
// Wheels definition and kinematics data
// ------------------------------------------------------------------------------------------------
#ifdef CONFIG_DIFFERENTIAL_2WD
enum Wheel
{
   WHEEL_LEFT = 0,
   WHEEL_RIGHT,
   MAX_WHEELS
};
#else
#error "Fatal Error: drive configuration flag is not defined!"
#endif

struct WheelsVelocity
{
   Timestamp timestamp{};
   float velocities[Wheel::MAX_WHEELS]{};
};

// ------------------------------------------------------------------------------------------------
// Environment and perception data
// ------------------------------------------------------------------------------------------------
#ifdef CONFIG_LIDAR_2D
struct Lidar2DData
{
   Timestamp timestamp{};
   float ranges[config::MAX_SCAN_POINTS]{};
   uint8_t intensities[config::MAX_SCAN_POINTS]{};

   float angleMin = 0.0f;
   float angleMax = 0.0f;
   float angleIncrement = 0.0f;
};
#endif

// ------------------------------------------------------------------------------------------------
// Safety monitoring
// ------------------------------------------------------------------------------------------------
#ifdef CONFIG_COLLISION
enum CollisionSide
{
   COL_FRONT = 0,
   COL_BACK,
   COL_LEFT,
   COL_RIGHT,
   MAX_COL_SIDE
};

struct CollisionData
{
   Timestamp timestamp{};
   bool hasCollision[CollisionSide::MAX_COL_SIDE]{};
};
#endif

}  // namespace pad::framework::core