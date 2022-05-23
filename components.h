//
// Created by juaquin on 22/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_COMPONENTS_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_COMPONENTS_H

#include <string>

class components {
protected:
    const char *text;
    float x1 = 0;
    float y1 = 0;
    float x2 = 0;
    float y2 = 0;
public:
    components(const char * t, float xi, float yi, float xf, float yf):
            text(t), x1(xi), y1(yi), x2(xf), y2(yf){};
    virtual void draw() = 0;
};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_COMPONENTS_H
