#include "SensorAggregator.hpp"

namespace pad::framework::core {

SensorAggregator::SensorAggregator(IMotionSensor* motionSensor, ISurroundingsSensor* environmentSensor,
                                   IHardwareMonitor* hardwareMonitor)
    : m_motionSensor(motionSensor), m_environmentSensor(environmentSensor), m_hardwareMonitor(hardwareMonitor)
{
}

bool SensorAggregator::update(UpdateGroup group) {}

SystemState SensorAggregator::getSystemState() const {}

}  // namespace pad::framework::core