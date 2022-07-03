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

    ALLEGRO_COLOR a;

public:
    item(int x, int y, ALLEGRO_COLOR color) : x1(x), y1(y), a(color) {};

    void draw() {
        al_draw_filled_circle(x1, y1, 5, a);
    }

    int get_x() { return x1; }

    int get_y() { return y1; }

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_ITEM_H
