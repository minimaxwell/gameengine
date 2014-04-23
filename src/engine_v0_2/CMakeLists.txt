cmake_minimum_required(VERSION 2.6)
project (engine_v0_2)
 
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
 
set(engine_v0_2_SRCS
	${PROJECT_SOURCE_DIR}/Background.cpp
	${PROJECT_SOURCE_DIR}/Color.cpp
	${PROJECT_SOURCE_DIR}/ConstantSpeedRotation.cpp
	${PROJECT_SOURCE_DIR}/ConstantSpeedScale.cpp
	${PROJECT_SOURCE_DIR}/Game.cpp
	${PROJECT_SOURCE_DIR}/Level.cpp
	${PROJECT_SOURCE_DIR}/LinearTrajectory.cpp
	${PROJECT_SOURCE_DIR}/Movement.cpp
	${PROJECT_SOURCE_DIR}/NonPlayer.cpp
	${PROJECT_SOURCE_DIR}/Player.cpp
	${PROJECT_SOURCE_DIR}/RectangularNonPlayer.cpp
	${PROJECT_SOURCE_DIR}/Rotation.cpp
	${PROJECT_SOURCE_DIR}/Scale.cpp
	${PROJECT_SOURCE_DIR}/Sequence.cpp
	${PROJECT_SOURCE_DIR}/TimelineSequence.cpp
	${PROJECT_SOURCE_DIR}/SinusoidalTrajectory.cpp
	${PROJECT_SOURCE_DIR}/StarBackground.cpp
	${PROJECT_SOURCE_DIR}/Trajectory.cpp
	${PROJECT_SOURCE_DIR}/Transformation.cpp
	${PROJECT_SOURCE_DIR}/MovementController.cpp
	${PROJECT_SOURCE_DIR}/KeyboardController.cpp
	${PROJECT_SOURCE_DIR}/JoystickController.cpp
	${PROJECT_SOURCE_DIR}/Main.cpp
	)
 
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

set(EXECUTABLE_NAME "engine_v0_2")
add_executable(${EXECUTABLE_NAME} ${engine_v0_2_SRCS})
target_link_libraries(${EXECUTABLE_NAME} sfml-audio sfml-window sfml-graphics sfml-system)
