cmake_minimum_required(VERSION 3.28.3)

project(Project_Name_Goes_Here LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Here is where we set output directories
set( OutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_BUILD_TYPE}")

set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OutputDir}/lib")

# Build static libraries
add_subdirectory( Libraries/GLFW_Library )
add_subdirectory( Libraries/ImGui_Library)
add_subdirectory( Libraries/GoogleTest_Library )

# Add the application subdirectory
add_subdirectory( Application )

# Add testing application
add_subdirectory( Testing )