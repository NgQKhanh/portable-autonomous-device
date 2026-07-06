#pragma once

#include <cstdint>

namespace pad::framework::domain {

enum class UpdateGroup : uint8_t
{
   FAST,
   SLOW
};

}  // namespace pad::framework::domain