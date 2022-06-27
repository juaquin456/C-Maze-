//
// Created by leandro on 11/06/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYER_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYER_H
#include <iostream>
#include <vector>
#include <memory>
#include <stdlib.h>
#include <time.h>
#include <list>
#include "item.h"
#include "Keyboard.h"
#include <unordered_map>
using namespace std;

class player {
    int ale_x();
protected:
    int x = 100;
    int y = 100;
    int x_score = 100;
    int y_score = 100;
    int puntos = 0;
    unordered_map<int, item> items;
    int cantidad_items = 0;
    Keyboard * k = Keyboard::get_instance();
    ALLEGRO_COLOR a = al_map_rgb_f(255, 0, 0);
    char mapa[20][32] = {"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
                         "x                             x",
                         "x                             x",
                         "x   xx xxxxxxx    x            ",
                         "xx x x x x  xxxxxxx            ",
                         "x          x xxxxxx            ",
                         "x x xxxx xxxx    xx            ",
                         "x x xxxx xxxx xxxxx            ",
                         "xxxxxx          xxx            ",
                         "xx       xxx  xxx x            ",
                         "xx  xxxxxxxx   x xx            ",
                         "xxx    xxxxxxxxx xx            ",
                         "xx  xxxx          x            ",
                         "xx  x    xxxxxxxxxx            ",
                         "x       xxxxxxxxxxx            ",
                         "xx   xxx          x            ",
                         "xx         xxxxxxxx            ",
                         "xxx xxxxxx   xxxxxx            ",
                         "x x xxxxxxxx   xxxx            ",
                         "xxxxxxxxxxxxxxxxxxx xxxxxxxx   "};

public:
    player(int c, int x, int y, ALLEGRO_COLOR color, int xs, int ys);
    void draw();
    virtual void alter_map();
    virtual void move() = 0;
};




#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYER_H
