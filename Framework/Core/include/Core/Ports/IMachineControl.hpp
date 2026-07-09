#pragma once

#include "Core/Models/TargetGoal.hpp"

namespace pad::framework::core {

class IMachineControl
{
public:
   virtual bool sendControlCommand(const TargetGoal& goal) = 0;
   virtual ~IMachineControl() = default;
};

}  // namespace pad::framework::core