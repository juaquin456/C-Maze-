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
#include "item.h"
#include "Keyboard.h"

using namespace std;

int ale_x();

int ale_y();

class player {
    vector<shared_ptr<item>> *items = nullptr;
    ALLEGRO_COLOR a = al_map_rgb_f(255, 0, 0);
    Keyboard *k = Keyboard::get_instance();
    int cantidad_items;
    float x = 100;
    float y = 100;
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
                         "xx  xxxxxxxx   x xx           ",
                         "xxx    xxxxxxxxx xx           ",
                         "xx  xxxx          x           ",
                         "xx  x    xxxxxxxxxx           ",
                         "x       xxxxxxxxxxx           ",
                         "xx   xxx          x           ",
                         "xx         xxxxxxxx           ",
                         "xxx xxxxxx   xxxxxx           ",
                         "x x xxxxxxxx   xxxx           ",
                         "xxxxxxxxxxxxxxxxxxx xxxxxxxx  "};

public:
    player(int c) : cantidad_items(c) {};

    void draw() {
        al_draw_filled_rectangle(x, y, x + 10, y + 10, a);
    }

    void alter_map() {
        for (int i = 1; i < 20;) {
            int a = ale_y();
            if (mapa[i][a] != 'x') {
                mapa[i][a] = '#';
                i += 4;
            }


        }


    }

    vector<std::shared_ptr<item>> draw_items() {
        vector<std::shared_ptr<item>> temp;


        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 32; j++) {
                if (mapa[i][j] == '#') {


                    temp.push_back(make_shared<item>(j * 20 + 8, i * 20 + 8));

                }
            }
        }
        return temp;
    }


    vector<std::shared_ptr<item>> get_items() {
        return *items;
    }

    void move() {
        k->update();
        if (k->is_key_down(ALLEGRO_KEY_UP))
            y -= 2;
        if (k->is_key_down(ALLEGRO_KEY_DOWN))
            y += 2;
        if (k->is_key_down(ALLEGRO_KEY_LEFT))
            x -= 2;
        if (k->is_key_down(ALLEGRO_KEY_RIGHT))
            x += 2;

    };

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYER_H
