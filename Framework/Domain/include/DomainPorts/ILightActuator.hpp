#pragma once

#include "DomainModels/CommandTypes.hpp"

namespace pad::framework::domain {

class ILightActuator
{
public:
   virtual bool set(const LightCommand& cmd) = 0;
   virtual ~ILightActuator() = default;
};

}  // namespace pad::framework::domain