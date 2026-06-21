# pad_src/Framework/Platform/CMakeLists.txt

# Select subfolder to build based on TARGET_PLATFORM argument
if(NOT DEFINED TARGET_PLATFORM)
    set(TARGET_PLATFORM "WIN" CACHE STRING "Target platform: WIN, LINUX, or FREERTOS")
endif()

if(TARGET_PLATFORM STREQUAL "WIN")
    add_subdirectory(win)
elseif(TARGET_PLATFORM STREQUAL "LINUX")
    add_subdirectory(linux)
elseif(TARGET_PLATFORM STREQUAL "FREERTOS")
    add_subdirectory(freertos)
else()
    message(FATAL_ERROR "Target platform '${TARGET_PLATFORM}' is invalid!")
endif()