#pragma once

#include <cstdint>

#include "Core/Model/Common.hpp"

namespace pad::framework::core {

struct BatteryData
{
   Timestamp timestamp{};
   float voltage = 0.0f;    // V
   float current = 0.0f;    // A
   uint8_t percentage = 0;  // 0 - 100%
   bool isCharging = false;
};

struct EncoderData
{
   Timestamp timestamp{};
   uint32_t tickCount = 0;
};

constexpr uint16_t MAX_SCAN_POINTS = 720;  // TODO: using config
struct Lidar2DData
{
   Timestamp timestamp{};
   float ranges[MAX_SCAN_POINTS]{};
   uint8_t intensities[MAX_SCAN_POINTS]{};

   float angleMin = 0.0f;
   float angleMax = 0.0f;
   float angleIncrement = 0.0f;
};

enum CollisionSide
{
   FRONT = 0,
   BACK,
   LEFT,
   RIGHT,
   MAX_COL_SIDE
};
struct CollisionData
{
   Timestamp timestamp{};
   bool hasCollision[CollisionSide::MAX_COL_SIDE]{};
};

}  // namespace pad::framework::core