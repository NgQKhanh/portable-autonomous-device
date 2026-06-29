#pragma once

#include <cstdint>

namespace pad::framework::domain {

enum class OperationMode : uint8_t
{
   INIT = 0,
   IDLE,
   ACTIVE,
   FAULT,
   SAFE_STATE,
   OP_MODE_COUNT
};

}  // namespace pad::framework::domain
