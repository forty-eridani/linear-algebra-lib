cmake_minimum_required(VERSION 3.10)
project(linear_algebra)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_DIRECTORY src)
set(COMPILE_DIR ${SOURCE_DIRECTORY}/c)
set(EXECUTABLE_NAME out)

include_directories(${SOURCE_DIRECTORY}/include)

set(BUILD_EXECUTABLE ON)
set(BUILD_LIBRARY ON)

if(BUILD_EXECUTABLE)
	add_executable(${EXECUTABLE_NAME} ${COMPILE_DIR}/main.c)
endif()

if(BUILD_LIBRARY)
	add_library(linear-algebra ${COMPILE_DIR}/main.c)
endif()
