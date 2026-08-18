#pragma once

#include <cstdint>

namespace pad::framework::core {

struct Timestamp
{
   uint64_t us;  // monotonic time since system start (microseconds)
};
struct Vector2
{
   float x;
   float y;
};
struct Vector3
{
   float x;
   float y;
   float z;
};
struct Point2D
{
   float x;
   float y;
};

}  // namespace pad::framework::core