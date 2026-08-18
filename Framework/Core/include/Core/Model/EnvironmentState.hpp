#pragma once

#include <cstdint>

#include "Core/Model/Common.hpp"
#include "Core/Model/SensorData.hpp"

namespace pad::framework::core {

constexpr uint16_t MAX_POINT_CLOUD_POINTS = 72;  // TODO: using config
struct PointCloud
{
   Timestamp timestamp;
   Point2D points[MAX_POINT_CLOUD_POINTS];
};

struct EnvironmentState
{
   PointCloud pointCloud;
   CollisionData contactState;
   // TODO: depth vision sensors (Camera RGB-D), upward facing sensor in the future
};

}  // namespace pad::framework::core