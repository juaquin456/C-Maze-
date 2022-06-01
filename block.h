//
// Created by juaquin on 01/06/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_BLOCK_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_BLOCK_H

#include "components.h"
#include<allegro5/allegro_primitives.h>
class block: public components{
    ALLEGRO_COLOR a = al_map_rgb_f(255,255,255);
public:
    using components::components;

    void draw() override{
        al_draw_filled_rectangle(x1, y1, x2, y2, a);
    }

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_BLOCK_H
