project( Application_Name VERSION 1.0.0)

# Here's all the source files for our applciation
set(Sources 
    src/FirstWindow.cpp
    src/main.cpp
    src/MainApp.cpp
    src/SampleData.cpp
)

# Here is where we set output directories
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OutputDir}/${PROJECT_NAME}")
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OutputDir}/${PROJECT_NAME}")

# Here's where we make the executable
add_executable(${PROJECT_NAME} ${Sources} )

# Here's where we include all our header files needed by the source files
target_include_directories( ${PROJECT_NAME} PRIVATE / include )

# Here we link in all of our libraries
target_link_libraries( ${PROJECT_NAME} glfw )
target_link_libraries( ${PROJECT_NAME} imgui )

# Imgui needs to use OpenGL so here's where we link to it.
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

