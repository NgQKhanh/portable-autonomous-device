#pragma once

#include "Core/Model/EnvironmentState.hpp"
#include "Core/Model/SensorData.hpp"

namespace pad::framework::core {

class PointCloudConverter
{
public:
   PointCloud convertToPointCloud2D(const Lidar2DData& data) const;
};

}  // namespace pad::framework::core