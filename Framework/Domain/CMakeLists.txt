# pad_src/Framework/Domain/CMakeLists.txt

# Create a static library for the DOMAIN implementation
add_library(domain STATIC
    src/MachineController.cpp
    src/StateMachine.cpp
    src/SafetyMonitor.cpp
    src/SensorAggregator.cpp
    src/ActuatorDispatcher.cpp
)

# Specify the public include directories for this target
target_include_directories(domain PUBLIC include)