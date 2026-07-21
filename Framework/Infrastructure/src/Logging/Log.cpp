#include "Infrastructure/Logging/Log.hpp"

#include <cstdarg>
#include <cstdio>

#include "Infrastructure/Logging/ILogger.hpp"
#include "Infrastructure/Logging/LogService.hpp"

namespace pad::framework::infrastructure::logging {

namespace {

constexpr std::size_t LOG_BUFFER_SIZE = 256;

constexpr const char* baseName(const char* path)
{
   const char* file = path;

   while (*path != '\0')
   {
      if (*path == '/' || *path == '\\')
      {
         file = path + 1;
      }
      ++path;
   }
   return file;
};

}  // namespace

void log(LogLevel level, const char* fileName, const char* func, const char* format, ...)
{
   LogLevel currentLevel = getLogLevel();
   uint8_t loggerCount = getLogCount();
   ILogger* const* loggers = getRegisteredLoggers();

   if (level < currentLevel || loggerCount == 0 || format == nullptr)
   {
      return;
   }

   char message[LOG_BUFFER_SIZE];

   va_list args;
   va_start(args, format);
   int len = std::vsnprintf(message, sizeof(message), format, args);
   va_end(args);
   if (len < 0)
   {
      return;
   }
   const char* safeFunc = (func != nullptr) ? func : "Unknown";
   const char* safeFileName = (fileName != nullptr) ? fileName : "Unknown";

   LogRecord record{level, baseName(safeFileName), safeFunc, message};

   for (uint8_t i = 0; i < loggerCount; i++)
   {
      if (loggers[i] != nullptr)
      {
         loggers[i]->write(record);
      }
   }
}

}  // namespace pad::framework::infrastructure::logging