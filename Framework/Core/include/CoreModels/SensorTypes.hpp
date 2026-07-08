#pragma once

#include <cstdint>

namespace pad::framework::core {

enum class UpdateGroup : uint8_t
{
   FAST,
   SLOW
};

}  // namespace pad::framework::core