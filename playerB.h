//
// Created by leandro on 18/06/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERB_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERB_H


#include <iostream>
#include <random>
#include "player.h"

class playerB : public player {
public:
    playerB(int c, int x, int y, ALLEGRO_COLOR color, int xs, int ys, char** map,clock_t tiempo,string username) : player(c, x, y, color, xs, ys,
        map,tiempo,username) {
        alter_map();
        who_was = "playerB";
    }

    void alter_map() override {
        player::alter_map();
    }

    void move() override {
        k->update();
        if (k->is_key_down(ALLEGRO_KEY_UP)) {
            if (mapa[(y - 7) / 20][x / 20] != 'x')
                y -= 2;
        }
        if (k->is_key_down(ALLEGRO_KEY_DOWN)) {
            if (mapa[(y + 7) / 20][x / 20] != 'x')
                y += 2;
        }
        if (k->is_key_down(ALLEGRO_KEY_LEFT)) {
            if (mapa[(y) / 20][(x - 7) / 20] != 'x')
                x -= 2;
        }
        if (k->is_key_down(ALLEGRO_KEY_RIGHT)) {
            if (mapa[(y) / 20][(x + 7) / 20] != 'x')
                x += 2;
        }
        if ((mapa[(y / 20)][(x / 20)]) == '#') {
            cout << y << "\t" << x << endl;
            mapa[(y / 20)][(x / 20)] = ' ';
            items.erase((int)(y / 20) * 54 + (int)x / 20);
            puntos++;
        }
    }
};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERB_H