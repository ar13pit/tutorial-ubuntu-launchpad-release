cmake_minimum_required(VERSION 3.15)

# set the project name and version
project(TestTutorial VERSION 1.0)

find_package(Tutorial REQUIRED)

add_executable(TestTutorial ${CMAKE_CURRENT_SOURCE_DIR}/test-tutorial.cxx)
target_link_libraries(TestTutorial ${Tutorial_LIBRARIES})
target_include_directories(TestTutorial ${Tutorial_INCLUDE_DIRS})
