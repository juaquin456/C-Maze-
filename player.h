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

using namespace std;

int ale_x();


class player {

protected:


    int cantidad_items = 0;

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
    player(int c) : cantidad_items(c) {};

    virtual void draw() = 0;

    virtual void alter_map() = 0;

    virtual list<std::shared_ptr<item>> draw_items() = 0;

    virtual void move()=0;
    virtual void verificar(list<std::shared_ptr<item>> &cnt)=0;

};




#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYER_H
