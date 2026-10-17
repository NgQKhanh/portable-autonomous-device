# pad_src/Framework/Core/CMakeLists.txt

# Create a static library for the CORE implementation
add_library(core STATIC

   # Algorithm
   src/Algorithm/Kinematics/DifferentialDriveKinematics.cpp

   # Sensor
   src/Sensor/SensorAggregator.cpp
)

# Specify the public include directories for this target
target_include_directories(core 
   PUBLIC 
      include
      "${CMAKE_BINARY_DIR}/generated"
)

# Link private dependencies:
# - 'infrastructure': Required for utility features like logging.
target_link_libraries(core
    PRIVATE
        infrastructure
)