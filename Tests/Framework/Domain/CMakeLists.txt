
add_executable(domain_tests
    test_domain.cpp
)

# Link with Google Test
target_link_libraries(domain_tests
    PRIVATE
    GTest::gtest_main
)

# Inform CTest to scan test cases
include(GoogleTest)
gtest_discover_tests(domain_tests)