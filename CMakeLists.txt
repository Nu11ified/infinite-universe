cmake_minimum_required(VERSION 3.25.1)

project(unigen_demo)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} 
    src/main.cpp 
    src/ui/jui.cpp
    #src/unigen/unigen.cpp
    #src/unigen/fast_rand.cpp
    vendored/imgui/imgui.cpp
    vendored/imgui/imgui_draw.cpp
    vendored/imgui/imgui_demo.cpp
    vendored/imgui/imgui_tables.cpp
    vendored/imgui/imgui_widgets.cpp
    vendored/imgui/rlImGui.cpp
)

find_package(raylib REQUIRED)   # supplied by Homebrew
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_include_directories(${PROJECT_NAME} PRIVATE 
    src
    src/ui
    src/model
    src/unigen
    vendored/imgui
    vendored/raylib
)

