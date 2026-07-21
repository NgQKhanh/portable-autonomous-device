#pragma once

#include "Infrastructure/Logging/LogLevel.hpp"

namespace pad::framework::infrastructure::logging {

struct LogRecord
{
   LogLevel level;
   const char* fileName;
   const char* func;
   const char* message;
};

class ILogger
{
public:
   virtual ~ILogger() = default;
   virtual void write(const LogRecord& record) = 0;
   virtual void flush() = 0;
};

}  // namespace pad::framework::infrastructure::logging