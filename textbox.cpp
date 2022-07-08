//
// Created by juaquin on 29/05/22.
//

#include "textbox.h"
void textbox::draw() {
    al_draw_rectangle(x1, y1, x2, y2, a, 0.1);
    const char* c = text.c_str();
    al_draw_text(al_create_builtin_font(), al_map_rgb_f(255, 255, 255), (x1 + x2) / 2, (y1 + y2) / 2, 1, c);
}

bool textbox::is_press_key() {
    return true;
}

void textbox::key_event(int key) {
    if (key < 26 and key > 0) {
        text += key + 'a' - 1;
    }
    else if (key == 67) { //enter
        f(text);
    }
    else if (key == 63) { //delete
        if (text.length() > 0)
            text.pop_back();
    }
    else {
        std::cout << key << std::endl;
    }
}