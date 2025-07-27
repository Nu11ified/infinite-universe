#include "raylib.h"
#include "rlImGui.h"

int main (int argc, char *argv[]) {

    InitWindow(900, 800, "uni_demo");
    SetTargetFPS(60);
    rlImGuiShutdown();
    CloseWindow();
    return 0;
}