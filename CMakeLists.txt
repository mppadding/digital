###
# Matthijs Padding's Standard C++ CMake.
# Mostly adapted from Jason Turner's CPP Starter Project
###

# TODO: Not tested with version <21
cmake_minimum_required(VERSION 3.21)

project(
    Digital
    VERSION 1.0
    DESCRIPTION "Digital Circuit Simulator"
    LANGUAGES CXX
)
include(cmake/StandardProjectSettings.cmake)

# Fake library where we set compile time options
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)
target_compile_options(project_options INTERFACE -g)

# Time Trace using clang
if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    option(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
    if(ENABLE_BUILD_WITH_TIME_TRACE)
        target_compile_options(project_options INTERFACE -ftime-trace)
    endif()
endif()

# Fake library where we set compiler warnings
add_library(project_warnings INTERFACE)

# Enable cache
#include(cmake/Cache.cmake)

# Default compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# Static analysis
include(cmake/StaticAnalyzers.cmake)

# IDE settings
include(cmake/IDE.cmake)

add_subdirectory(src)

option(ENABLE_TESTING "Enable Test Builds" OFF)

if(ENABLE_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()
