#pragma once

#include "DomainModels/TargetGoal.hpp"

namespace pad::framework::domain {

class IMachineControl
{
public:
   virtual bool sendControlCommand(const TargetGoal& goal) = 0;
   virtual ~IMachineControl() = default;
};

}  // namespace pad::framework::domain