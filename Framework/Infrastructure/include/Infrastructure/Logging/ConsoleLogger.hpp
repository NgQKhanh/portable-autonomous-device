#pragma once

#include "Infrastructure/Logging/ILogger.hpp"

namespace pad::framework::infrastructure::logging {

class ConsoleLogger : public ILogger
{
public:
   void write(const LogRecord& record) override;
   void flush() override;
};

}  // namespace pad::framework::infrastructure::logging