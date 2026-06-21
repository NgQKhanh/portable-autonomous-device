# # pad_src/Framework/Adapters/CMakeLists.txt

# Select subfolder to build based on TARGET_PLATFORM argument
if(NOT DEFINED TARGET_PLATFORM)
    set(TARGET_PLATFORM "WIN" CACHE STRING "Target platform: WIN, LINUX, or FREERTOS")
endif()

if(TARGET_PLATFORM STREQUAL "WIN")
    add_subdirectory(mock)
elseif(TARGET_PLATFORM STREQUAL "LINUX")
    add_subdirectory(linux_sysfs)
#elseif(TARGET_PLATFORM STREQUAL "FREERTOS")
#    add_subdirectory(xxx_hal)
else()
    message(FATAL_ERROR "Target platform '${TARGET_PLATFORM}' is invalid!")
endif()