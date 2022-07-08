//
// Created by juaquin on 22/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_BUTTON_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_BUTTON_H

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_ttf.h>

#include <functional>

#include "components.h"
#include "Display.h"

class button : public components {
    const char* text;
    std::function<void()> f;
    ALLEGRO_COLOR a = al_map_rgb_f(255, 255, 255);
public:
    button(const char* t, float xi, float yi, float xf, float yf, std::function<void()>& f) : text(t),
        components(xi, yi, xf,
            yf), f(f) {};

    void draw() override;

    bool is_on_bound() override;

    void click_event() override;

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_BUTTON_H