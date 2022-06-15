//
// Created by leandro on 11/06/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_ITEM_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_ITEM_H
#include <iostream>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

class item {
    int x1 = 0;
    int y1 = 0;

    ALLEGRO_COLOR a = al_map_rgb_f(0,255,0);

public:
    item(int x,int y):x1(x),y1(y){};
    void draw() {
        al_draw_filled_circle(x1,y1,4,a);
    }

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_ITEM_H
