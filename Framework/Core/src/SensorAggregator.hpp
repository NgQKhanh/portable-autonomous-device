#pragma once

#include "Core/Models/SystemState.hpp"

namespace pad::framework::core {

// Forward Declaration:
class IHardwareMonitor;
class IMotionSensor;
class ISurroundingsSensor;

class SensorAggregator
{
public:
   SensorAggregator(IMotionSensor* motionSensor, ISurroundingsSensor* environmentSensor,
                    IHardwareMonitor* hardwareMonitor);
   bool update(UpdateGroup group);
   SystemState& getSystemState() const;

private:
   SystemState m_systemState;

   IMotionSensor* m_motionSensor;
   ISurroundingsSensor* m_environmentSensor;
   IHardwareMonitor* m_hardwareMonitor;
};

}  // namespace pad::framework::core