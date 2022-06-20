//
// Created by leandro on 18/06/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERA_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERA_H

#include <iostream>
#include "player.h"

class playerA : player {
    vector<shared_ptr<item>> *items = nullptr;
    float x = 100;
    float y = 100;
    ALLEGRO_COLOR a = al_map_rgb_f(255, 0, 0);


public:
    playerA(int c) : player(c) {};

    void draw() override {
        al_draw_filled_rectangle(x, y, x + 10, y + 10, a);
    }

    void alter_map() override {

        int c = 0;
        int p = 2;
        while (c < cantidad_items) {
            int i = ale_x();

            if (mapa[p][i] != 'x' && mapa[p][i] != 'O') {
                mapa[p][i] = '#';
                c++;
                p += 2;
            }
        }


    }

    vector<std::shared_ptr<item>> draw_items() override {
        vector<std::shared_ptr<item>> temp;


        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 32; j++) {
                if (mapa[i][j] == '#') {


                    temp.push_back(make_shared<item>(j * 20 + 8, i * 20 + 8, a));


                }
            }
        }
        return temp;
    }

    void move() override {
        k->update();
        if (k->is_key_down(ALLEGRO_KEY_W))
            y -= 2;
        if (k->is_key_down(ALLEGRO_KEY_S))
            y += 2;
        if (k->is_key_down(ALLEGRO_KEY_A))
            x -= 2;
        if (k->is_key_down(ALLEGRO_KEY_D))
            x += 2;

    }


};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERA_H
