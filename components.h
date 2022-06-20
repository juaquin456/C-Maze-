//
// Created by juaquin on 22/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_COMPONENTS_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_COMPONENTS_H

#include <string>
#include "Mouse.h"

class components {
protected:
    float x1 = 0;
    float y1 = 0;
    float x2 = 0;
    float y2 = 0;
public:
    components(float xi, float yi, float xf, float yf) :
            x1(xi), y1(yi), x2(xf), y2(yf) {};

    virtual void draw() = 0;

    virtual bool is_on_bound() { return false; };

    virtual void click_event() {};

    virtual bool is_press_key() { return false; };

    virtual void key_event(int key) {};
};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_COMPONENTS_H
