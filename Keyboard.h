//
// Created by juaquin on 22/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_KEYBOARD_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_KEYBOARD_H

#include <allegro5/allegro5.h>

class Keyboard {
    inline static Keyboard* instance;
    ALLEGRO_KEYBOARD_STATE* ks = nullptr;

    Keyboard();

public:
    static Keyboard* get_instance();

    void update();

    template<typename T>
    bool is_key_down(T keycode) {
        return al_key_down(ks, keycode);
    }

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_KEYBOARD_H