#pragma once

#include "Assert.hpp"

namespace pad::framework::infrastructure::utilities {

using AssertFailureHandler = void (*)(const AssertFailureInfo&);
void registerAssertFailureHandler(AssertFailureHandler handler);

}