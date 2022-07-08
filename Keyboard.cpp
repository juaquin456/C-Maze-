//
// Created by juaquin on 22/05/22.
//

#include "Keyboard.h"

Keyboard::Keyboard() {
    ks = new ALLEGRO_KEYBOARD_STATE;
}

Keyboard* Keyboard::get_instance() {
    if (instance == nullptr) instance = new Keyboard();
    return instance;
}

void Keyboard::update() {
    al_get_keyboard_state(ks);
}