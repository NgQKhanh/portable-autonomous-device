#pragma once

#include "Core/Model/Device.hpp"

namespace pad::framework::core {

template <typename T>
struct SensorResult
{
   DeviceStatus status;
   T data;
};

template <typename T>
class ISensor
{
public:
   virtual SensorResult<T> read() = 0;
   virtual ~ISensor() = default;
};

}  // namespace pad::framework::core