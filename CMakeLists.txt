cmake_minimum_required(VERSION 3.21)
project(Lab_9 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lab_9 
    src/main.cpp
    src/Library.cpp
    src/DatabaseRepository.cpp
    src/EmailNotificationService.cpp
    src/FileRepository.cpp
)
target_include_directories(Lab_9 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Google Test
find_package(GTest CONFIG REQUIRED)
enable_testing()

add_executable(Lab_9_Tests 
    tests/LibraryTests.cpp
    src/Library.cpp
)
target_include_directories(Lab_9_Tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(Lab_9_Tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(Lab_9_Tests)

# Kata (2)
add_executable(GildedRose Part_2_KATA/main.cpp)
