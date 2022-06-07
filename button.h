//
// Created by juaquin on 22/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_BUTTON_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_BUTTON_H

#include "components.h"
#include "Display.h"


#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
class button: public  components {
    const char * text;
    int current_interface;
    int next_interface;
    ALLEGRO_COLOR a = al_map_rgb_f(255,255,255);
public:
    button(const char *t, float xi, float yi, float xf, float yf, int cur_i,int next_i): text(t), components(xi,yi,xf,yf), current_interface(cur_i),next_interface(next_i)  {};

    void draw() override{
        if(this->is_on_bound()){
            a = al_map_rgb_f(255,0,0);
        }
        else{
            a = al_map_rgb_f(255,255,255);
        }
        al_draw_filled_rectangle(x1, y1, x2, y2, a);
        al_draw_text(al_create_builtin_font(), al_map_rgb_f(0,0,0) , (x1+x2)/2, (y1+y2)/2, 1,text);
    }

    bool is_on_bound() override {
        Mouse *m = Mouse::getInstance();
        float x = m->get_x();
        float y = m->get_y();

        if (x > x2 or x < x1) {
            return false;
        }
        if (y < y1 or y > y2) {
            return false;
        }
        return true;
    }

    int is_clicked() override{
        return next_interface;
    }

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_BUTTON_H
