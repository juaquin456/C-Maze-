//
// Created by juaquin on 18/06/22.
//

#include "label.h"
void label::draw() {
    al_draw_filled_rectangle(x1, y1, x2, y2, color_bg);
    al_draw_text(al_create_builtin_font(), color_text, (x1 + x2) / 2, (y1 + y2) / 2, 1, text.c_str());
}