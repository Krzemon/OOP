cmake_minimum_required(VERSION 3.1.0)
project (lab13)

# prevent for in-source building
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

# if(${LP_1})
#   set(LOOP_1 1)
# else()
#   set(LOOP_1 0)
# endif()

# if(${LP_2})
#   set(LOOP_2 1)
# else()
#   set(LOOP_2 0)
# endif()

add_definitions(-DPROJECTPATH=\"${PROJECT_SOURCE_DIR}\" -DLOOP_1=${LOOP_1} -DLOOP_2=${LOOP_2})

set(CMAKE_BUILD_TYPE Debug) #Release
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

set(INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${INCLUDES})

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} Main.cpp ${SOURCES})
