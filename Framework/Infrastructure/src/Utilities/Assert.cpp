#include "Infrastructure/Utilities/Assert.hpp"

#include <cstdlib>

#include "Infrastructure/Utilities/AssertService.hpp"

namespace pad::framework::infrastructure::utilities {

namespace {

AssertFailureHandler g_failureHandler = nullptr;

void reportAssert(const AssertFailureInfo& info)
{
   (void)info;
   // TODO:
   // - Log
   // - send to UART
}

void notifyFailureHandler(const AssertFailureInfo& info)
{
   if (g_failureHandler != nullptr)
   {
      g_failureHandler(info);
   }
}

[[noreturn]] void terminate()
{
// TODO:
// Should be implemented in Platform
#if defined(_MSC_VER)
   __debugbreak();
   std::abort();
#elif defined(__GNUC__) || defined(__clang__)
   __builtin_trap();
#else
   std::abort();
#endif
}

}  // namespace

void registerAssertFailureHandler(AssertFailureHandler handler)
{
   g_failureHandler = handler;
}

[[noreturn]] void handleAssertFailure(const AssertFailureInfo& info)
{
   // Using a guard variable to avoid recursive assert, this case happend when
   // a callback or logger accidentally triggers a PAD_ASSERT
   static bool handling = false;

   reportAssert(info);
   notifyFailureHandler(info);
   if (handling)
   {
      terminate();
   }
   handling = true;
}

}  // namespace pad::framework::infrastructure::utilities