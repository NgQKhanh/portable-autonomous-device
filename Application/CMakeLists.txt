# pad_src/Application/CMakeLists.txt

add_executable(pad_app
    # Here is the place will contain file main.cpp
    main.cpp
)

# Application is the place compose all the system, it need to link  to all modules
target_link_libraries(pad_app
    PRIVATE
        domain
        adapters
        platform
        infrastructure
)