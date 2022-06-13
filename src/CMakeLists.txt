set(EXECUTABLE_SOURCES
    "main.cpp"

    "sim/component.cpp"
    "sim/net.cpp"
    "sim/pin.cpp"

    "sim/components/gates/and_gate.cpp" 
)

# Add FMTlib
find_package(fmt REQUIRED)

add_executable(main ${EXECUTABLE_SOURCES})
add_library(main_lib ${EXECUTABLE_SOURCES})

target_include_directories(main     PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(main_lib PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(main      PRIVATE project_options project_warnings fmt::fmt)
target_link_libraries(main_lib  PRIVATE project_options project_warnings fmt::fmt)

add_custom_target(run
    COMMAND main
    DEPENDS main
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)

add_custom_target(debug
    COMMAND gdb build/src/main
    DEPENDS main
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)
