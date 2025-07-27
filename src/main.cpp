#include "color.hpp"
#include "imgui.h"
#include "jui.hpp"
#include "raylib.h"
#include "rlImGui.h"

void init_imgui() {
    rlImGuiSetup( true);

    //scaling 
    ImGuiStyle &style = ImGui::GetStyle();
    style.Colors[ImGuiCol_WindowBg] = JUI::to_imvec4(Jcolor::Crust);
    style.Colors[ImGuiCol_Text] = JUI::to_imvec4(Jcolor::Cornsilk);
    style.Colors[ImGuiCol_FrameBg] = JUI::to_imvec4(Jcolor::Greenyell);
    style.WindowRounding = 8.0f;
    style.FrameRounding = 4.0f;
    style.WindowPadding = {12, 12}; 
    style.FramePadding = {6, 6};
    style.CellPadding = {4, 4};

    style.FontSizeBase = 28.f;
}

int main (int argc, char *argv[]) {
    InitWindow(900, 800, "uni_demo");
    SetTargetFPS(75);

    init_imgui();
    JUI::Jui ui{};

    //loop 
    bool should_run{true};

    while (should_run) {
        if (IsKeyPressed(KEY_CAPS_LOCK)) {
            should_run = false;
        }

        BeginDrawing();
        rlImGuiBegin();
        ClearBackground(JUI::to_ray_color(Jcolor::Crust));

        ui.update();
        ui.draw();
        ui.show_ui();

        rlImGuiEnd();
        EndDrawing();
    }


    rlImGuiShutdown();
    CloseWindow();
    return 0;
}