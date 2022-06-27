#pragma once
#include<iostream>
#include "player.h"
#include "tsp.h"
using namespace std;

class bot : public player {
    vector<pair<int, int>> route = { {0,0} };
    int cambio_x = 0;
    int cambio_y = 0;
    int sz = 0;
    int itr = 0;
    int pasos = 0;

public:
    using player::player;

    void alter_map() override {
        player::alter_map();

        route = getPath({ 1,1 }, mapa, 20, 32);
        sz = (int)route.size();
    }

    void move()override {

        if (itr + 1 < sz) {


            x += 2 * cambio_x;
            y += 2 * cambio_y;
            if (pasos % 10 == 0) {

                cambio_y = route[itr + 1].first - route[itr].first;
                cambio_x = route[itr + 1].second - route[itr].second;
                itr++;

            }
            //cout << pasos << '\n';
            pasos++;

        }
        if (itr + 1 == sz) {
            x += 2 * cambio_x;
            y += 2 * cambio_y;
            if (pasos % 10 == 0) itr++;
            pasos++;

        }
        if (itr + 1 > sz) {
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
        }
        if((mapa[(y/20)][(x/20)]) =='#'){
            cout << y << "\t" << x << endl;
            mapa[(y/20)][(x/20)] = ' ';
            items.erase((int)(y/20)*32 + (int)x/20);
        }
    }
};
