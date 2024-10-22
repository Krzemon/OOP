cmake_minimum_required(VERSION 3.14)

project(lab01 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Requirement of this standard
set(CMAKE_CXX_EXTENSIONS OFF)

# Build type - Debug by default, but can be changed to Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories(${INCLUDE_DIR})

# -------------------------------------------------#
# 1
#set(SOURCES
#    ${SOURCE_DIR}/Main.cpp
#    ${SOURCE_DIR}/PascalTriangle.cpp
#    ${SOURCE_DIR}/SierpinskiTriangle.cpp
#)

#add_executable(${PROJECT_NAME} ${SOURCES})

# 2
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
# -------------------------------------------------#

# Adding a PROJECTPATH ​​macro definition (optional)
#target_compile_definitions(${PROJECT_NAME} PRIVATE
#PROJECTPATH="${PROJECT_SOURCE_DIR}")


# Optional - installation of the executable file
#install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# Unit tests - add if you have test files
#enable_testing()
#add_subdirectory(tests)
