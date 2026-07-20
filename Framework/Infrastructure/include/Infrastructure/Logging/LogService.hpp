#pragma once

#include <cstdint>

namespace pad::framework::infrastructure::logging {

// Forward declarations
enum class LogLevel : uint8_t;
class ILogger;

void registerLogger(ILogger* logger);
void unRegisterLogger(ILogger* logger);
void clearLogger();
ILogger* const* getRegisteredLoggers();
void setLogLevel(LogLevel level);
LogLevel getLogLevel();
uint8_t getLogCount();
void flush();

}  // namespace pad::framework::infrastructure::logging