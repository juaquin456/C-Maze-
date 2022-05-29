//
// Created by juaquin on 29/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_TEXTBOX_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_TEXTBOX_H

#include "components.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_ttf.h>

class textbox : public components{
    ALLEGRO_COLOR a = al_map_rgb_f(255,255,255);
public:
    using components::components;

    void draw() override{
        al_draw_rectangle(x1, y1, x2, y2, a, 0.1);
        al_draw_text(al_create_builtin_font(), al_map_rgb_f(0,0,0) , (x1+x2)/2, (y1+y2)/2, 1,text);
    }
    // Funcion que permita escribir texto
};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_TEXTBOX_H
