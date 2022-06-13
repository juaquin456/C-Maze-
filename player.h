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

int ale();

class player {
    vector<shared_ptr<item>> *items = nullptr;
    ALLEGRO_COLOR a = al_map_rgb_f(255,0,0);
    Keyboard * k = Keyboard::get_instance();
    int cantidad_items;
    float x = 100;
    float y = 100;

public:
    player(int c):cantidad_items(c){};
    void draw() {
        al_draw_filled_rectangle(x, y, x + 10, y + 10, a);
    }
    void draw_items(){
        for(int i = 0;i<cantidad_items;i++){
        int a = ale();
        int b = ale();
        item A(a,b);
        A.draw();

        }

    };
    void move(){
        k->update();
        if(k->is_key_down(ALLEGRO_KEY_UP))
            y-=2;
        if(k->is_key_down(ALLEGRO_KEY_DOWN))
            y+=2;
        if(k->is_key_down(ALLEGRO_KEY_LEFT))
            x-=2;
        if(k->is_key_down(ALLEGRO_KEY_RIGHT))
            x+=2;

};

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYER_H
