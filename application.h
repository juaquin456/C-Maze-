//
// Created by juaquin on 22/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_APPLICATION_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_APPLICATION_H



#include "interface.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>

#include "Keyboard.h"
#include "Mouse.h"


class application {
    int H = 1080;
    int V = 720;
    interface v;
public:
    application();

    void run();
};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_APPLICATION_H