#pragma once

#include "DomainModels/CommandTypes.hpp"

namespace pad::framework::domain {

class IMotionActuator
{
public:
   virtual bool set(const MotionCommand& cmd) = 0;
   virtual void emergencyStop() = 0;
   virtual ~IMotionActuator() = default;
};

}  // namespace pad::framework::domain