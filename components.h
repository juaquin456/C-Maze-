//
// Created by juaquin on 22/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_COMPONENTS_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_COMPONENTS_H

#include <string>
#include "Mouse.h"
class components {
protected:
    const char *text;
    float x1 = 0;
    float y1 = 0;
    float x2 = 0;
    float y2 = 0;
public:
    components(const char *t, float xi, float yi, float xf, float yf) :
            text(t), x1(xi), y1(yi), x2(xf), y2(yf) {};

    virtual void draw() = 0;
    virtual bool is_on_bound() {
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

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_COMPONENTS_H
