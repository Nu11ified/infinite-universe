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
    SetTargetFPS(60);
    rlImGuiShutdown();
    CloseWindow();
    return 0;
}