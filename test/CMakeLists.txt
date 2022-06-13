# Fetch GoogleTest from github
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

add_executable(
    tests
    "basic_test.cpp"
)

target_include_directories(tests PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(
    tests
    PRIVATE
        project_warnings
        project_options
        gtest_main
        main_lib
)

include(GoogleTest)
gtest_discover_tests(tests)
