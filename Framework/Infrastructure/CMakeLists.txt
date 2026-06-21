# pad_src/Framework/Infrastructure/CMakeLists.txt

# Create a static library for the INFRASTRUCTURE implementation
add_library(infrastructure STATIC
    src/Logger.cpp
)

# Specify the public include directories for this target
target_include_directories(infrastructure PUBLIC include)