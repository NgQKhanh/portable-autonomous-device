cmake_minimum_required(VERSION 3.15)

project(PortableAutonomousDevice VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- DEPENDENCY MANAGEMENT ---
include(FetchContent)

# Google Test lib
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
  SOURCE_DIR     "${CMAKE_SOURCE_DIR}/ThirdParty/google_test"
)

# Disable GTest installation flags to avoid building unnecessary components
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

# Download and make the library available
FetchContent_MakeAvailable(googletest)

# --- SOURCE SUBDIRECTORIES ---

add_subdirectory(Framework)
add_subdirectory(Application)

# Option to enable/disable unit test builds.
# Disabled by default to keep normal builds faster.
option(BUILD_TEST "Build unit tests" OFF)

if(BUILD_TEST)
    enable_testing()
    add_subdirectory(Tests)
endif()
