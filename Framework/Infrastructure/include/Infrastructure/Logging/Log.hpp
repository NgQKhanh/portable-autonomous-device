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

namespace {

void log(LogLevel level, const char* fileName, const char* func, const char* format, ...);

}

}  // namespace pad::framework::infrastructure::logging

#define LOG_DBG(format, ...)                                                                                        \
   pad::framework::infrastructure::logging::log(pad::framework::infrastructure::logging::LogLevel::DEBUG, __FILE__, \
                                                __func__, format, ##__VA_ARGS__)

#define LOG_INF(format, ...)                                                                                       \
   pad::framework::infrastructure::logging::log(pad::framework::infrastructure::logging::LogLevel::INFO, __FILE__, \
                                                __func__, format, ##__VA__ARGS__)

#define LOG_WRN(format, ...)                                                                                          \
   pad::framework::infrastructure::logging::log(pad::framework::infrastructure::logging::LogLevel::WARNING, __FILE__, \
                                                __func__, format, ##__VA__ARGS__)

#define LOG_ERR(format, ...)                                                                                        \
   pad::framework::infrastructure::logging::log(pad::framework::infrastructure::logging::LogLevel::ERROR, __FILE__, \
                                                __func__, format, ##__VA__ARGS__)
