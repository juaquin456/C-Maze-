//
// Created by juaquin on 22/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_APPLICATION_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_APPLICATION_H

#include <vector>
#include <memory>
#include "interface.h"
class application {
    int H = 1080;
    int V = 720;
    interface v;
public:
    application();
    void run();
};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_APPLICATION_H
