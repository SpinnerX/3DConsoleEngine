cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME 3DConsoleRenderer)

project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)
set(PROJECT_INCLUDE_DIR 3DConsoleEngine)

# Setting C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

find_package(formatCpp REQUIRED)

get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if(isMultiConfig)
    if(NOT "Asan" IN_LIST CMAKE_CONFIGURATION_TYPES)
        list(APPEND CMAKE_CONFIGURATION_TYPES Asan)
    endif()
else()
    set(allowedBuildTypes Asan Debug Release RelWithDebInfo MinSizeRel)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "${allowedBuildTypes}")

    if(CMAKE_BUILD_TYPE AND NOT CMAKE_BUILD_TYPE IN_LIST allowedBuildTypes)
        message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}")
    endif()
endif()

set(CMAKE_C_FLAGS_ASAN
    "${CMAKE_C_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer" CACHE STRING
    "Flags used by the C compiler for Asan build type or configuration." FORCE)

set(CMAKE_CXX_FLAGS_ASAN
    "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer" CACHE STRING
    "Flags used by the C++ compiler for Asan build type or configuration." FORCE)

set(CMAKE_EXE_LINKER_FLAGS_ASAN
    "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fsanitize=address" CACHE STRING
    "Linker flags to be used to create executables for Asan build type." FORCE)

set(CMAKE_SHARED_LINKER_FLAGS_ASAN
    "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} -fsanitize=address" CACHE STRING
    "Linker lags to be used to create shared libraries for Asan build type." FORCE)

include_directories(
    ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/include
)

# Better way instead of GLOBBING 
set(
    all_src
    ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/include/core/Window.h
    ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/include/math/Vector.h
    ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/include/shapes/Line.h

    ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/src/core/Window.cpp
    ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/src/main.cpp
)

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")


add_executable(${PROJECT_NAME} ${all_src})


include(${PROJECT_SOURCE_DIR}/cmake/glfw.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/sdl2.cmake)
target_link_libraries(${PROJECT_NAME} formatCpp)