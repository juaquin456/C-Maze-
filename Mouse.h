//
// Created by juaquin on 22/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_MOUSE_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_MOUSE_H

#include <allegro5/allegro5.h>

class Mouse {
    inline static Mouse *instance = nullptr;
    float x, y;

    Mouse();

public:
    static Mouse *getInstance();

    template<typename T>
    void move(T position) {
        x = position.x;
        y = position.y;
    }

    float get_x() {
        return x;
    }

    float get_y() {
        return y;
    }
};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_MOUSE_H
