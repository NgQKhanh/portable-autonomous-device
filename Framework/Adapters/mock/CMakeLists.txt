# pad_src/Framework/Adapters/mock/CMakeLists.txt

# Create a static library for the Mock adapters implementation
add_library(adapters STATIC
    # Sensor
    src/Sensor/SingleEncoderAdapter.cpp
)

# Specify the public include directories for this target
target_include_directories(adapters PUBLIC include)


# Link private dependencies:
# - 'core': Required because adapters must implement Port Interfaces defined in the core layer.
# - 'infrastructure': Required for utility features like logging.
target_link_libraries(adapters
    PRIVATE
        core
        infrastructure
)