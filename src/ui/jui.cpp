#include "jui.hpp"
#include "color.hpp"
#include "raylib.h"
#include "imgui.h"


void JUI::Jui::show_ui() {};

void JUI::Jui::draw() {
  int num_sec_x = GetScreenWidth() / sec_size;
  int num_sec_y = GetScreenHeight() / sec_size;

  float radius = sec_size / 2.0;

  for (size_t x = 0; x < num_sec_x; x++) {
    auto line_color = to_ray_color(Jcolor::Cornsilk);
    //DrawLine(x * sec_size, 0, x * sec_size, 
    //  GetScreenHeight(), line_color);
    for (size_t y = 0; y < num_sec_y; y++) {

      //DrawLine(0, y * sec_size, GetScreenWidth(), y * sec_size,
      //  line_color);
      
      Point global_sector = Point{static_cast<int>(cam.x + x),
                                  static_cast<int>(cam.y + y)};

      this->frand.seed = Jrand::PerfectlyHasThem(global_sector.x, global_sector.y);
      
      if (frand.randInteger(0, 20) == 1) {
        // draw at screen-relative coordinates so stars remain visible while scrolling
        int screen_x = static_cast<int>(x * sec_size + radius);
        int screen_y = static_cast<int>(y * sec_size + radius);
        DrawCircle(screen_x, screen_y, static_cast<int>(radius),
                   to_ray_color(Jcolor::Slateblue));
      }
    }
  }
};

void JUI::Jui::update() {
  const float KEYPAD_SENSE = this-> sec_size * 4.0f * GetFrameTime();

  if (IsKeyDown(KEY_S)) {
    this -> cam.y += KEYPAD_SENSE;
  }

  if (IsKeyDown(KEY_W)) {
    this -> cam.y -= KEYPAD_SENSE;
  }

  if (IsKeyDown(KEY_A)) {
    this -> cam.x -= KEYPAD_SENSE;
  }

  if (IsKeyDown(KEY_D)) {
    this -> cam.x += KEYPAD_SENSE;
  }
};

Color JUI::to_ray_color(Jcolor::JColor col) {
  return Color{col.r, col.g, col.b, col.a};
}

ImVec4 JUI::to_imvec4(const Jcolor::JColor c) {
  return ImVec4{
      static_cast<float>(c.r) / 255.0f,
      static_cast<float>(c.g) / 255.0f,
      static_cast<float>(c.b) / 255.0f,
      static_cast<float>(c.a) / 255.0f};
}