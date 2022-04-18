cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage")

project(banking)

option(BUILD_TESTS "Build tests" ON)

add_library(banking STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/banking/Account.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/banking/Transaction.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/banking
)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/googletest)
    add_executable(check ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp)
    target_compile_options(check PRIVATE)
    target_link_libraries(check banking gtest_main)
    add_test(NAME unit_tests COMMAND check)
endif()