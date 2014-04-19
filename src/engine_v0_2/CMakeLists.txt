cmake_minimum_required(VERSION 2.6)
project (engine_v0_2)
 
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
 
set(engine_v0_2_SRCS
	${PROJECT_SOURCE_DIR}/Color.cpp
	)
 
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

set(EXECUTABLE_NAME "engine_v0_2")
add_executable(${EXECUTABLE_NAME} ${engine_v0_2_SRCS})
target_link_libraries(${EXECUTABLE_NAME} sfml-audio sfml-window sfml-graphics sfml-system)
