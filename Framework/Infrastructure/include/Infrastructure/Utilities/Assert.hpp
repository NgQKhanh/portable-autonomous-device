#pragma once

#include <cstdint>

namespace pad::framework::infrastructure::utilities {

struct AssertFailureInfo
{
   const char* expression;
   const char* file;
   const char* function;
   const char* message;
   std::uint32_t line;
};

[[noreturn]] void handleAssertFailure(const AssertFailureInfo& info);

}  // namespace pad::framework::infrastructure::utilities

#ifdef PAD_ASSERT_ENABLE

#define PAD_ASSERT(expr)                                                       \
   do                                                                          \
   {                                                                           \
      if (!(expr))                                                             \
      {                                                                        \
         pad::framework::infrastructure::utilities::AssertFailureInfo info{    \
             #expr, __FILE__, __func__, nullptr, __LINE__,                     \
         };                                                                    \
         pad::framework::infrastructure::utilities::handleAssertFailure(info); \
      }                                                                        \
   } while (0)

#define PAD_ASSERT_MSG(expr, msg)                                              \
   do                                                                          \
   {                                                                           \
      if (!(expr))                                                             \
      {                                                                        \
         pad::framework::infrastructure::utilities::AssertFailureInfo info{    \
             #expr, __FILE__, __func__, msg, __LINE__,                         \
         };                                                                    \
         pad::framework::infrastructure::utilities::handleAssertFailure(info); \
      }                                                                        \
   } while (0)

#else

#define PAD_ASSERT(expr) ((void)0)
#define PAD_ASSERT_MSG(expr, msg) ((void)0)

#endif

#define PAD_UNREACHABLE()                                                   \
   do                                                                       \
   {                                                                        \
      pad::framework::infrastructure::utilities::AssertFailureInfo info{    \
          "Unreachable", __FILE__, __func__, nullptr, __LINE__,             \
      };                                                                    \
      pad::framework::infrastructure::utilities::handleAssertFailure(info); \
   } while (0)