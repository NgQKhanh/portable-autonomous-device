
add_executable(core_test
    # Algorithm
    Algorithm/Test_DifferentialDriveKinematics.cpp
)

# Link with Google Test
target_link_libraries(core_test
    PRIVATE
        core
        GTest::gtest_main
)

# Inform CTest to scan test cases
include(GoogleTest)
gtest_discover_tests(core_test)