//
// Created by juaquin on 22/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_APPLICATION_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_APPLICATION_H

#include <vector>
#include <memory>
#include "components.h"
class application {
    std::vector<std::shared_ptr<components>> menu;
public:
    application();
    void run();
};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_APPLICATION_H
