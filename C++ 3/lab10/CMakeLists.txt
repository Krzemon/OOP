cmake_minimum_required(VERSION 3.1.0)
project(lab10)

# Prevent in-source building
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif()

set(CMAKE_BUILD_TYPE Debug)  # Release
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

# Include directories
set(INCLUDES ${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Używamy target_include_directories dla specyficznych celów
# przy tworzeniu executable

# Tworzenie głównego executable z głównym plikiem i plikami źródłowymi
add_executable(${PROJECT_NAME} Main.cpp ${SOURCES})

# Flaga do testowania błędu kompilacji
option(ENABLE_ERROR_TEST "Włącz test błędu kompilacji" OFF)

# Określamy ścieżki do plików nagłówkowych dla tego celu
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDES})

# Dodajemy pliki źródłowe do tego celu
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

# Jeśli flaga ENABLE_ERROR_TEST jest włączona, dodajemy definicję preprocesora
if(ENABLE_ERROR_TEST)
    target_compile_definitions(${PROJECT_NAME} PRIVATE ENABLE_ERROR_TEST)
endif()

