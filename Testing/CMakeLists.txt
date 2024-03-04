project( TestMyApplication )

set(Sources 
    src/pch.cpp
    src/test.cpp

    #../LoadPathApp/src/your_amazing_code.cpp
)

include_directories( ${PROJECT_NAME} include )
include_directories( ${PROJECT_NAME} ../Application/include )

# Here is where we set output directories
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OutputDir}/${PROJECT_NAME}")
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OutputDir}/${PROJECT_NAME}")

add_executable( ${PROJECT_NAME} ${Sources} )

# Here is where we would pass any defines needed for testing
# set_target_properties( ${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS "SYMBOL_NAME_GOES_HERE")

# Here we link all the other libraries that our code being tested used
target_link_libraries( ${PROJECT_NAME} PRIVATE gtest )