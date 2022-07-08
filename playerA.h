//
// Created by leandro on 18/06/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERA_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERA_H


#include "player.h"

class playerA : public player {
    ALLEGRO_SAMPLE* pop = al_load_sample("../sounds/floop2_x.wav");

public:
    playerA(int c, int x, int y, ALLEGRO_COLOR color, int xs, int ys, char** map, string username, function<void()>& f)
        : player(c, x, y, color, xs, ys,
            map, username, f) {
        alter_map();
        who_was = "playerA";
    }

    void alter_map() override {
        player::alter_map();
    }

    void move() override {
        if (empieza) {
            current_tiempo = clock();
            empieza = 0;
        }
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
            if (mapa[(y) / 20][(x - 7) / 20] != 'x')
                x -= 2;
        }
        if (k->is_key_down(ALLEGRO_KEY_D)) {
            if (mapa[(y) / 20][(x + 7) / 20] != 'x')
                x += 2;
        }
        if ((mapa[(y / 20)][(x / 20)]) == '#') {
            al_play_sample(pop, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            cout << y << "\t" << x << endl;
            mapa[(y / 20)][(x / 20)] = ' ';
            items.erase((int)(y / 20) * 54 + (int)x / 20);
            puntos++;
            if (puntos == cantidad_items) {
                fstream myfile;
                myfile.open("../rank", ios::out | ios::app);
                std::cout << "here";
                myfile << name << ' ' << static_tiempo << '\n';
                myfile.close();
                seen = 0;
                f();
            }
        }
    }

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYERA_H