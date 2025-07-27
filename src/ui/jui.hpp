#ifndef JUI_UI
#define JUI_UI

#include "color.hpp"
#include "imgui.h"
#include "raylib.h"

namespace JUI {

Color to_ray_color(Jcolor::JColor col);
ImVec4 to_imvec4(const Jcolor::JColor c);

}

#endif // JUI_UI