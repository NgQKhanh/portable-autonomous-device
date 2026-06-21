# pad_src/Framework/Platform/win/CMakeLists.txt

# Create a static library for the Windows platform runtime implementation
add_library(platform STATIC
    src/PcRuntime.cpp
)

# Specify the public include directories for this target
target_include_directories(platform PUBLIC include)

# Link private dependencies required by the platform layer
target_link_libraries(platform
    PRIVATE
        infrastructure
)

