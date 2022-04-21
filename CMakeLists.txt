cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage")

project(banking)

option(BUILD_TESTS "Build tests" ON)

add_library(banking STATIC
        ./banking/Account.cpp
        ./banking/Transaction.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        ./banking
)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(./googletest)
    add_executable(check ./tests/test.cpp)
    target_link_libraries(check banking gtest_main)
    add_test(NAME unit_tests COMMAND check)
endif()
