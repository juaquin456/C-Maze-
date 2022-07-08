//
// Created by juaquin on 22/05/22.
//

#include "button.h"

void button::click_event() {
    f();
}

bool button::is_on_bound() {
    Mouse* m = Mouse::getInstance();
    float x = m->get_x();
    float y = m->get_y();

    if (x > x2 or x < x1) {
        return false;
    }
    if (y < y1 or y > y2) {
        return false;
    }
    return true;
}

void button::draw() {
    if (this->is_on_bound()) {
        a = al_map_rgb_f(255, 0, 0);
    }
    else {
        a = al_map_rgb_f(255, 255, 255);
    }
    al_draw_filled_rectangle(x1, y1, x2, y2, a);
    al_draw_text(al_create_builtin_font(), al_map_rgb_f(0, 0, 0), (x1 + x2) / 2, (y1 + y2) / 2, 1, text);
}