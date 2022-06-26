#pragma once
#include<iostream>
#include "player.h"
#include "tsp.h"
using namespace std;

class bot : player {
    vector<shared_ptr<item>>* items = nullptr;
    Keyboard* k = Keyboard::get_instance();
    int x = 48;//60;
    int y = 28;//40;
    ALLEGRO_COLOR a = al_map_rgb_f(255, 255, 0);
    vector<pair<int, int>> route = { {0,0} };
    int cambio_x = 0;
    int cambio_y = 0;
    int sz = 0;
    int itr = 0;
    int pasos = 0;



public:
    bot(int c) : player(c) {};

    void draw() override {
        al_draw_filled_rectangle(x-5, y-5, x + 5, y + 5, a);
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

        route = getPath({ 1,1 }, mapa, 20, 32);
        sz = (int)route.size();
    }
    list<std::shared_ptr<item>> draw_items() override {
        list<std::shared_ptr<item>> temp;


        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 32; j++) {
                if (mapa[i][j] == '#') {
                    temp.push_back(make_shared<item>(j * 20 + 8, i * 20 + 8, a));
                }
            }
        }
        return temp;
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

    }
    void verificar(list<std::shared_ptr<item>>& cnt) override {


    }
    int get_x() { return x; }
    int get_y() { return y; }


};
