project( ImGuiLibrary )

set(Sources 
    imgui/imgui.cpp
    imgui/imgui_widgets.cpp 
    imgui/imgui_tables.cpp 
    imgui/imgui_draw.cpp 
    imgui/misc/cpp/imgui_stdlib.cpp         # need this to use std::string
    imgui/backends/imgui_impl_glfw.cpp      # need this to use GLFW library
    imgui/backends/imgui_impl_opengl3.cpp   # need this to use openGL3 library
)

# Set the name of the ImGui library to imgui
set(LibraryName imgui)

# Build the library with the sourse files above
add_library( ${LibraryName} STATIC ${Sources} )

# Link the GLFW library into ImGui
target_link_libraries( ${LibraryName} PUBLIC glfw)

# Here's the include directories needed by anyone else using the imgui library
target_include_directories( ${LibraryName} PUBLIC imgui )
target_include_directories( ${LibraryName} PUBLIC imgui/misc/cpp )
target_include_directories( ${LibraryName} PUBLIC imgui/backends )