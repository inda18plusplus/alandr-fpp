cmake_minimum_required(VERSION 3.09)
project(FiMplusplus)

set(CMAKE_CXX_STANDARD 17)
set(EXEC_NAME FiMplusplus)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/out/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

option(ENABLE_TIMING "Time the paring and execution of the program" FALSE)

if (ENABLE_TIMING)
	add_definitions(-DTIMING)
endif (ENABLE_TIMING)

include_directories(src)
file(GLOB_RECURSE SOURCE_FILES "src/*.[ch]pp")

add_executable(${EXEC_NAME} ${SOURCE_FILES})

target_link_libraries(${EXEC_NAME} stdc++fs)

#Find and link libfmt
	find_package(fmt REQUIRED)
	target_link_libraries(${EXEC_NAME} fmt::fmt)