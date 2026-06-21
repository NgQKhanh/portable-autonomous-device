# pad_src/Framework/Adapters/mock/CMakeLists.txt

# Create a static library for the Mock adapters implementation
add_library(adapters STATIC
    src/MockInputAdapters.cpp
    src/MockOutputAdapters.cpp
)

# Specify the public include directories for this target
target_include_directories(adapters PUBLIC include)


# Link private dependencies:
# - 'domain': Required because adapters must implement Port Interfaces defined in the domain layer.
# - 'infrastructure': Required for utility features like logging.
target_link_libraries(adapters
    PRIVATE
        domain
        infrastructure
)