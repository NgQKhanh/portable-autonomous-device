#pragma once

#include <cstdint>

#include "Core/Model/Common.hpp"
#include "Core/Model/SensorData.hpp"
#include "PadParameters.hpp"

namespace pad::framework::core {

struct PointCloud
{
   Timestamp timestamp;
   Point2D points[config::MAX_POINT_CLOUD_POINTS];
};

struct EnvironmentState
{
   PointCloud pointCloud;
   CollisionData contactState;
   // TODO: depth vision sensors (Camera RGB-D), upward facing sensor in the future
};

}  // namespace pad::framework::core