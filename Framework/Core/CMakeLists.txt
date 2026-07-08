# pad_src/Framework/Core/CMakeLists.txt

# Create a static library for the CORE implementation
add_library(core STATIC
    src/MachineController.cpp
    src/StateMachine.cpp
    src/SafetyMonitor.cpp
    src/SensorAggregator.cpp
    src/ActuatorDispatcher.cpp
)

# Specify the public include directories for this target
target_include_directories(core PUBLIC include)