//
// Created by juaquin on 29/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_TEXTBOX_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_TEXTBOX_H

#include <iostream>
#include <functional>
#include "components.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_ttf.h>

class textbox : public components{
    std::string text;
    int current_interface;
    int next_interface;
    std::function<void()> f;
    ALLEGRO_COLOR a = al_map_rgb_f(255,255,255);
public:
    textbox(const char * t, float xi, float yi, float xf, float yf, std::function<void()>& f): text(t), components(xi, yi, xf, yf), f(f) {};

    void draw() override{
        al_draw_rectangle(x1, y1, x2, y2, a, 0.1);
        const char * c= text.c_str();
        al_draw_text(al_create_builtin_font(), al_map_rgb_f(255,255,255) , (x1+x2)/2, (y1+y2)/2, 1,c);
    }
    bool is_press_key() override{
        return true;
    }

    std::string get_name(){
        return text;
    }

    void key_event(int key) override{
        if(key < 26 and key >0){
            text += key+'a'-1;
        }
        else if (key == 67){ //enter
            f();
        }
        else if (key == 63){ //delete
            if (text.length()>0)
                text.pop_back();
        }
        else{
            std::cout << key << std::endl;
        }
    }

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_TEXTBOX_H
