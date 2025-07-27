#include "jui.hpp"
#include "color.hpp"
#include "raylib.h"
#include "imgui.h"
#include "unigen.hpp"


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
        auto star = UGEN::GenerateStar(
          global_sector.x, global_sector.y, this->star_system_rand);

        DrawCircle((x * sec_size) + radius, y * sec_size + radius,
          (star.Radius / 2100.0) * radius, star_to_color(star.Color));
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

Color JUI::Jui::star_to_color(GameModel::StarColor star_color) {
  switch (star_color) {
    case GameModel::White:
      return to_ray_color(Jcolor::Cornsilk);
    case GameModel::Blue:
      return to_ray_color(Jcolor::Lightblue);
    case GameModel::Red:
      return to_ray_color(Jcolor::Violetred);
    case GameModel::Yellow:
      return to_ray_color(Jcolor::Greenyell);
    case GameModel::Orange:
      return to_ray_color(Jcolor::Orange);
    case GameModel::Gold: 
      return to_ray_color(Jcolor::Burlywood);
  }
  return to_ray_color(Jcolor::Purp);
}