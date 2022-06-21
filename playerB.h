//
// Created by leandro on 18/06/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERB_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERB_H


#include <iostream>
#include "player.h"
#include <random>

class playerB : player {
    vector<shared_ptr<item>> *items = nullptr;
    int x = 600;
    int y = 600;
    ALLEGRO_COLOR a = al_map_rgb_f(255, 255, 0);

public:
    playerB(int c) : player(c) {};

    void draw() override {
        al_draw_filled_rectangle(x-5, y-5, x + 5, y + 5, a);
    }

    void alter_map() override {

        int c = 0;
        int p = 2;
        while (c < cantidad_items) {
            int i = ale_x();

            if (mapa[p][i] != 'x' && mapa[p][i] != '#') {
                mapa[p][i] = 'O';
                c++;
                p += 2;
            }
        }


    }

    vector<std::shared_ptr<item>> draw_items() override {
        vector<std::shared_ptr<item>> temp;


        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 32; j++) {
                if (mapa[i][j] == 'O') {


                    temp.push_back(make_shared<item>(j * 20 + 8, i * 20 + 8, a));


                }
            }
        }
        return temp;
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
            if (mapa[(y) / 20][(x-7) / 20] != 'x')
                x -= 2;
        }
        if (k->is_key_down(ALLEGRO_KEY_RIGHT)) {
            if (mapa[(y) / 20][(x+7) / 20] != 'x')
                x += 2;
        }
    }


};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERB_H
