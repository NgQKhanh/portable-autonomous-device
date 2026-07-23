#pragma once

#include <cstdint>

namespace pad::framework::infrastructure::logging {

enum class LogLevel : uint8_t
{
   DEBUG,
   INFO,
   WARNING,
   ERROR
};

}  // namespace pad::framework::infrastructure::logging