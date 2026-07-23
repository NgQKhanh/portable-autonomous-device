# pad_src/Framework/Infrastructure/CMakeLists.txt

# Create a static library for the INFRASTRUCTURE implementation
add_library(infrastructure STATIC
    src/Logging/ConsoleLogger.cpp
    src/Logging/Log.cpp
    src/Logging/LogService.cpp
    src/Utilities/Assert.cpp
)

# Specify the public include directories for this target
target_include_directories(infrastructure PUBLIC include)