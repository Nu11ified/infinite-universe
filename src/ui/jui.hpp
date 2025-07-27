#ifndef JUI_UI
#define JUI_UI

#include "color.hpp"
#include "imgui.h"
#include "raylib.h"
#include "fast_rand.hpp"
#include "model.hpp"
#include <optional>

namespace JUI {

struct Point {
  int x;
  int y;
};

class Jui {
  public: 
    void show_ui();
    void update();
    void draw();

  private:
    int sec_size{32};
    Jrand::FastRand frand{};
    Jrand::FastRand star_system_rand{};
    Point cam{0, 0 };
    Point mouse_pos{0, 0};
    std::optional<GameModel::StarSystem> hovered_star{std::nullopt};
    Color star_to_color(GameModel::StarColor star_color);
};

Color to_ray_color(Jcolor::JColor col);
ImVec4 to_imvec4(const Jcolor::JColor c);

}

#endif // JUI_UI