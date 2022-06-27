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

int ale_x();


class player {

protected:
    int x = 100;
    int y = 100;
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
    player(int c, int x, int y, ALLEGRO_COLOR color) : cantidad_items(c), x(x), y(y), a(color) {};

    void draw(){
        al_draw_filled_rectangle(x-5, y-5, x + 5, y + 5, a);
        for(auto [k, v]:items){
            v.draw();
        }
    };

    virtual void alter_map(){
        int c=0;
        int p =2;
        while(c < cantidad_items){
            int i = ale_x();

            if(mapa[p][i]!='x'&&mapa[p][i]!='O'){
                mapa[p][i]='#';
                items.insert({p*32+i, item(i*20+8, p*20+8, a)});
                c++;
                p+=2;
            }
        }

    };
    virtual void move() = 0;
};




#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYER_H
