//
// Created by juaquin on 29/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_TEXTBOX_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_TEXTBOX_H

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <functional>
#include "components.h"


class textbox : public components {
    std::string text;
    std::function<void(std::string)> f;
    ALLEGRO_COLOR a = al_map_rgb_f(255, 255, 255);
public:
    textbox(const char* t, float xi, float yi, float xf, float yf, std::function<void(std::string)>& f) : text(t),
        components(xi,
            yi,
            xf,
            yf),
        f(f) {};

    void draw() override;

    bool is_press_key() override;

    void key_event(int key) override;

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_TEXTBOX_H