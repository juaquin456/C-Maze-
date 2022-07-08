//
// Created by juaquin on 18/06/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_LABEL_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_LABEL_H

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_ttf.h>
#include "components.h"
#include<string>

class label : public components {
    std::basic_string<char> text;
    ALLEGRO_COLOR color_bg = al_map_rgb_f(0, 0, 0);
    ALLEGRO_COLOR color_text = al_map_rgb_f(255, 255, 255);
public:
    label(std::basic_string<char> t, float xi, float yi, float xf, float yf, const ALLEGRO_COLOR& color_bg,
        const ALLEGRO_COLOR& color_text) : text(t), components(xi, yi, xf, yf), color_bg(color_bg),
        color_text(color_text) {};

    void draw() override;
};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_LABEL_H