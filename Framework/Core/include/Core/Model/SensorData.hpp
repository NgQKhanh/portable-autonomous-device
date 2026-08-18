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
   uint32_t leftTickCount = 0;
   uint32_t rightTickCount = 0;
};
struct ImuData
{
   Timestamp timestamp{};
   Vector3 acceleration{};     // m/s^2
   Vector3 angularVelocity{};  // rad/s
};
constexpr uint16_t MAX_SCAN_POINTS = 720;  // TODO: using config
struct LidarData
{
   Timestamp timestamp{};
   float ranges[MAX_SCAN_POINTS];

   float angleMin = 0.0f;
   float angleMax = 0.0f;
   float angleIncrement = 0.0f;
};
struct CollisionData
{
   Timestamp timestamp{};
   bool hasCollision = false;
};

}  // namespace pad::framework::core