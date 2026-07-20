#include "Infrastructure/Logging/LogService.hpp"

#include "Infrastructure/Logging/Log.hpp"

namespace pad::framework::infrastructure::logging {

namespace {

constexpr uint8_t MAX_LOGGERS = 4;
ILogger* g_loggers[MAX_LOGGERS] = {nullptr};
LogLevel g_currentLevel = LogLevel::INFO;
uint8_t g_loggerCount = 0;

}  // namespace

void registerLogger(ILogger* logger) {};
void unRegisterLogger(ILogger* logger) {};
void clearLogger() {};

ILogger* const* getRegisteredLoggers()
{
   return g_loggers;
};

void setLogLevel(LogLevel level)
{
   g_currentLevel = level;
};

LogLevel getLogLevel()
{
   return g_currentLevel;
};

uint8_t getLogCount()
{
   return g_loggerCount;
};

void flush() {};

}  // namespace pad::framework::infrastructure::logging