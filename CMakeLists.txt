cmake_minimum_required(VERSION 3.10)
project(linear_algebra)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_DIRECTORY src)
set(COMPILE_DIR ${SOURCE_DIRECTORY}/c)
set(INCLUDE_DIR ${SOURCE_DIRECTORY}/include)
set(EXECUTABLE_NAME out)

set(SOURCE_FILES ${COMPILE_DIR}/vector.c
				 ${COMPILE_DIR}/matrix.c)

include_directories(${INCLUDE_DIR}/)

set(BUILD_EXECUTABLE ON)
set(BUILD_LIBRARY ON)

if(BUILD_EXECUTABLE)
	add_executable(${EXECUTABLE_NAME} ${COMPILE_DIR}/main.c
									  ${SOURCE_FILES})
endif()

if(BUILD_LIBRARY)
	add_library(linear-algebra ${SOURCE_FILES})
endif()
