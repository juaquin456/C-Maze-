//
// Created by leandro on 18/06/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERA_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERA_H
#include <iostream>
#include "player.h"

class playerA: public player{

public:
    using player::player;

    void alter_map() override{
        player::alter_map();
    }

    void move()override {
        k->update();
        if (k->is_key_down(ALLEGRO_KEY_W)) {
            if (mapa[(y - 7) / 20][x / 20] != 'x')
                y -= 2;
        }
        if (k->is_key_down(ALLEGRO_KEY_S)) {
            if (mapa[(y + 7) / 20][x / 20] != 'x')
                y += 2;
        }
        if (k->is_key_down(ALLEGRO_KEY_A)) {
            if (mapa[(y) / 20][(x-7) / 20] != 'x')
                x -= 2;
        }
        if (k->is_key_down(ALLEGRO_KEY_D)) {
            if (mapa[(y) / 20][(x+7) / 20] != 'x')
                x += 2;
        }
        if((mapa[(y/20)][(x/20)]) =='#'){
            cout << y << "\t" << x << endl;
            mapa[(y/20)][(x/20)] = ' ';
            items.erase((int)(y/20)*54 + (int)x/20);
            puntos++;
        }
    }

};



#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERA_H
