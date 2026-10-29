add_custom_target(pad_test)

add_subdirectory(Framework/Core)

add_dependencies(pad_test
   core_test
)
