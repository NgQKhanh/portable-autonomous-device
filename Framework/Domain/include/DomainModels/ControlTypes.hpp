#pragma once

#include <cstdint>

namespace pad::framework::domain {

enum class ControlMask : uint8_t
{
   NONE = 0,
   MOTION = (1 << 0),
   LIGHT = (1 << 1),
   CTR_MASK_CNT,
};

}  // namespace pad::framework::domain