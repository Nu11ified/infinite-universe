cmake_minimum_required(VERSION 3.25.1)

project(unigen_demo)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} 
    src/main.cpp 
    src/ui/jui.cpp
    #src/unigen/unigen.cpp
    src/unigen/fast_rand.cpp
    vendored/imgui/imgui.cpp
    vendored/imgui/imgui_draw.cpp
    vendored/imgui/imgui_demo.cpp
    vendored/imgui/imgui_tables.cpp
    vendored/imgui/imgui_widgets.cpp
    vendored/imgui/rlImGui.cpp
)

# --- raylib linking -----------------------------------------------------------
# Linux: link against the vendored static library shipped in the repo.
# macOS / Windows (and any other OS): use a system-installed raylib package.

if(UNIX AND NOT APPLE)
    # On Linux we keep the vendored static build of raylib
    target_link_libraries(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/vendored/raylib/libraylib.a)
else()
    # macOS (Homebrew), Windows (vcpkg/MSYS2), etc.
    find_package(raylib REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE 
    src
    src/ui
    src/model
    src/unigen
    vendored/imgui
    vendored/raylib
)

