#include "jui.hpp"
#include "color.hpp"
#include "raylib.h"

Color JUI::to_ray_color(Jcolor::JColor col) {
  return Color{col.r, col.g, col.b, col.a};
}

ImVec4 JUI::to_imvec4(const Jcolor::JColor c) {
  return ImVec4{
    static_cast<float>(c.r) / 255.0f,
    static_cast<float>(c.g) / 255.0f,
    static_cast<float>(c.b) / 255.0f,
    static_cast<float>(c.a) / 255.0f
  };
}