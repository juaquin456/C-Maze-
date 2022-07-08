//
// Created by leandro on 11/06/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYER_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYER_H

#include <unordered_map>
#include <allegro5/allegro_font.h>
#include <fstream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "item.h"
#include "Keyboard.h"
#include "components.h"
#include <ctime>
#include <functional>
using namespace std;

class player : public components {
    int ale_x();

protected:
    Keyboard* k = Keyboard::get_instance();
    ALLEGRO_COLOR a = al_map_rgb_f(255, 0, 0);
    unordered_map<int, item> items;
    clock_t current_tiempo;
    clock_t static_tiempo;
    string who_was;
    int x = 100;
    int y = 100;
    int x_score = 100;
    int y_score = 100;
    int puntos = 0;
    bool seen = 1;
    int cantidad_items = 0;
    string name = "Guest420";
    function<void()> f;
    char mapa[33][54];
    bool empieza = 1;
public:
    player(int c, int x, int y, ALLEGRO_COLOR color, int xs, int ys, char**& map, string username, function<void()>& f);

    void draw();

    virtual void alter_map();

    virtual void move() = 0;
};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_PLAYER_H