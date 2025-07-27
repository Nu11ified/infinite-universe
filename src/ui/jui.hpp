#ifndef JUI_UI
#define JUI_UI

#include "color.hpp"
#include "imgui.h"
#include "raylib.h"

namespace JUI {

class Jui {
  public: 
    void show_ui();
    void update();
    void draw();

  private:
    int sec_size{32};
};

Color to_ray_color(Jcolor::JColor col);
ImVec4 to_imvec4(const Jcolor::JColor c);

}

#endif // JUI_UI