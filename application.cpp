//
// Created by juaquin on 22/05/22.
//

#include "application.h"

#include <iostream>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#include "Keyboard.h"
#include "Mouse.h"
#include "Display.h"
#include "item.h"
#include "player.h"


void must_init(bool test, const char *description)
{
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

application::application() {
    v.render_vista(1);
}

void application::run() {

    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_install_mouse(), "mouse");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    auto &disp = Display<ALLEGRO_DISPLAY*>::getInstance(al_create_display(1080, 720))->get();
    //ALLEGRO_DISPLAY* disp = al_create_display(1080, 720);
    must_init(*disp, "display");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_primitives_addon(), "primitives");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(*disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    Keyboard * k = Keyboard::get_instance();
    Mouse * m = Mouse::getInstance();
    al_start_timer(timer);
    player P(6);
    P.alter_map();
    P.draw_items();
    auto acv = P.draw_items();





    while(1)
    {
        al_wait_for_event(queue, &event);
        k->update();
        if(k->is_key_down(ALLEGRO_KEY_ESCAPE))
            done = true;

        switch(event.type)
        {
            case ALLEGRO_EVENT_MOUSE_AXES:
                m->move(event.mouse);
                break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                for(auto const e:v.getVista()){
                    if(e->is_on_bound()){
                        v.render_vista(e->is_clicked());
                    }
                }
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                for(auto const e:v.getVista()){
                    if(e->is_press_key())
                        e->key_event(event.keyboard.keycode);
                }
                break;

            case ALLEGRO_EVENT_TIMER:
                redraw = true;
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));

            /*al_draw_filled_rectangle(250, 10, 390, 30, al_map_rgb(255, 0, 0));
            al_draw_text(font, al_map_rgb(0,0,0), 300, 20,0, "OPCION 1");

            al_draw_filled_rectangle(250, 40, 390, 60, al_map_rgb(255, 0, 0));
            al_draw_text(font, al_map_rgb(0,0,0), 300, 50,0, "OPCION 2");

            al_draw_filled_rectangle(250, 70, 390, 90, al_map_rgb(255, 0, 0));
            al_draw_text(font, al_map_rgb(0,0,0), 300, 80,0, "OPCION 3");
*/

            for(auto const e:v.getVista()){
                e->draw();
            }
            //Dibujar mapa
            /*for(int i=0; i<20; i++){
                for(int j=0; j<20; j++){
                    if(mapa[i][j]=='x'){
                        al_draw_filled_rectangle(i*35,j*35, (i+1)*35-5, (j+1)*35-5, al_map_rgb(0,255,255));
                    }
                }
            }*/

            for(auto const i:acv){
                i->draw();
            }

            P.draw();
            P.move();


            al_flip_display();
            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(*disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}
