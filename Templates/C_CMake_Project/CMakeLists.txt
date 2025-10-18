cmake_minimum_required(VERSION 3.8)

project(SampleProject)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SAMPLE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
file(GLOB_RECURSE SAMPLE_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

add_executable(SampleProject "${SAMPLE_SOURCES}" "${SAMPLE_HEADERS}")

link_directories(lib)
target_include_directories(SampleProject "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_libraries(SampleProject)
