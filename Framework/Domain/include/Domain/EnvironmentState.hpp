#pragma once

#include <cstdint>

namespace pad::framework::domain {

// Dummy data
// TODO: using external config file to set obstacle sensor count
#define OBSTACLE_SENSOR_COUNT 3

struct EnvironmentState
{
   float obstacleDistances[OBSTACLE_SENSOR_COUNT];
   float groundInclination;
   int16_t ambientTemperatureCentiDeg;
   bool cliffDetected;
};

}  // namespace pad::framework::domain