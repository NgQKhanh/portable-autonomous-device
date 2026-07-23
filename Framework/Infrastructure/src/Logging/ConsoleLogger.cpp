
#include "Infrastructure/Logging/ConsoleLogger.hpp"

#include <cstdio>

namespace pad::framework::infrastructure::logging {

namespace {

const char* toString(LogLevel level)
{
   switch (level)
   {
      case LogLevel::DEBUG:
         return "DEBUG";
         break;

      case LogLevel::INFO:
         return "INFO";
         break;

      case LogLevel::WARNING:
         return "WARNING";
         break;

      case LogLevel::ERROR:
         return "ERROR";
         break;

      default:
         return "UNKNOWN";
   }
}

}  // namespace

void ConsoleLogger::write(const LogRecord& record)
{
   std::printf("[%s] %s:%s() - %s\n", toString(record.level), record.fileName, record.func, record.message);
}

void ConsoleLogger::flush()
{
   std::fflush(stdout);
};

}  // namespace pad::framework::infrastructure::logging