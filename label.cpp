//
// Created by juaquin on 18/06/22.
//

#include "label.h"

void label::draw() {
    al_draw_filled_rectangle(x1, y1, x2, y2, a);
    al_draw_text(al_create_builtin_font(), al_map_rgb_f(0, 0, 0), (x1 + x2) / 2, (y1 + y2) / 2, 1, text.c_str());
}
