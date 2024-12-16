cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(snake)

add_subdirectory(lib/SDL)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(${CMAKE_PROJECT_NAME})

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE SDL3::SDL3)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCES} )