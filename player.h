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
    char mapa[33][55] = {"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
                         "x x     xxx       x        x x    x   xx     xxxxxx xx",
                         "x   x x   x xxxxx x xxxxxx   x xxxxxx  xxx x      x  x",
                         "xxxxx xxx x x  x  x  x   x x   x    xx x xxx xxxx xx x",
                         "x   x x x   x xx xx xx xxx x x      x           x  x x",
                         "x x   x xxxxx    x   x x   x xxxxxx xx xxxx xxx x xx x",
                         "x xxxxx     x xxxx x   x x x  x   x  x  x     x   x  x",
                         "x x     x xxx x    xx xx xxxx xxx xx    x x xxx x   xx",
                         "x xxxxxxx   x xx x    x     x   x  xxxx x   x   x xxxx",
                         "x x     xx xx  x xxxx x xxx xx  x xx x  x x xx xx    x",
                         "x x xxx x   x xx    x x x    xx   x  x xx x  x x   x x",
                         "x   x x   x x    xx x x   xx  x x x       xx x x x x x",
                         "x xxx   x x x xx x  x x x       x xxxx  x  x     x x x",
                         "x x   x x x    x xx x x xxxxxxx x  x x xx xxxx x x x x",
                         "x x xxx x xxx xx    x   x x   x x  x x  x      x x xxx",
                         "x   x   x x x    xxxx x   xx xx    x   xxxx xxxx x   x",
                         "xxxxx xxx x   xx x    x x  x  x x  x x x     x     xxx",
                         "x     x     x  xxx xxxx xx x xxxxx   x x xxx xxxxx x x",
                         "xxxx xx x xxx      x     x         x x     x   x x x x",
                         "x x   x x x   xx xxx xxx x x  xxxxxx x xxxxxxx   x   x",
                         "x xxx xxx xx xx   x  x x x xx x    x x         x   x x",
                         "x x   x    x x  x x xx x x  x x xx   xxxxx x xxx x x x",
                         "x   x xxxx x xxxx x x    xx x x  x x x x   x x x x xxx",
                         "x x x x  x   x  x x x  x  x x   xx x   x x x   x x   x",
                         "x xxx xx x x xx x x xx xx x   x x  x x   x xxx x x x x",
                         "x x      x x    x x  x  x   xxx xxxxxx x x       x x x",
                         "x xxxx xxx xxx xx   xxx x x x x   x  x x   x xxxxx xxx",
                         "x    x       x  x x x x   x x x x    x   x xxx      xx",
                         "xxxx x xxx x xx   x   x x x x x xxxx x x x   xx xxx  x",
                         "x    x   x x  xxx x x x x   x x x  x x x xxx  x x x  x",
                         "xx xxx xxx xx x x xxx x xxx x   x xx   x x x xx x xx x",
                         "x  x   x        x     x   x x x    x xxx   x    x    x",
                         "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"};

public:
    player(int c, int x, int y, ALLEGRO_COLOR color, int xs, int ys);
    void draw();
    virtual void alter_map();
    virtual void move() = 0;
};




#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYER_H
