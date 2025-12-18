cmake_minimum_required(VERSION 3.21)

project(TestOCCT LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /Zc:__cplusplus /utf-8 /EHsc")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target)

find_package(OpenCASCADE REQUIRED)

message("===============================================")
message("OCCT INCLUDE_DIR: ${OpenCASCADE_INCLUDE_DIR}")
message("OCCT LIBRARY_DIR: ${OpenCASCADE_LIBRARY_DIR}")
message("OCCT BINARY_DIR: ${OpenCASCADE_BINARY_DIR}")
message("OCCT LIBRARIES: ${OpenCASCADE_LIBRARIES}")
message("===============================================")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)
