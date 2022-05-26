//
// Created by juaquin on 22/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_BUTTON_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_BUTTON_H

#include "components.h"
#include "Display.h"


#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
class button: public  components {
    ALLEGRO_COLOR a = al_map_rgb_f(255,255,255);
public:
    using components::components;

    void draw() override{
        if(this->is_on_bound()){
            a = al_map_rgb_f(255,0,0);
        }
        else{
            a = al_map_rgb_f(255,255,255);
        }
        al_draw_filled_rectangle(x1, y1, x2, y2, a);
        al_draw_text(al_create_builtin_font(), al_map_rgb_f(0,0,0) , (x1+x2)/2, (y1+y2)/2, 1,text);
    }

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_BUTTON_H
