#pragma once

#include "Core/Models/CommandTypes.hpp"

namespace pad::framework::core {

class ILightActuator
{
public:
   virtual bool set(const LightCommand& cmd) = 0;
   virtual ~ILightActuator() = default;
};

}  // namespace pad::framework::core