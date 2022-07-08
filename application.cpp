//
// Created by juaquin on 22/05/22.
//

#include "application.h"


void must_init(bool test, const char* description) {
    if (test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

application::application() {
    v = interface(H, V);
    v.render_vista(1);
}

void application::run() {
    srand(time(nullptr));
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

    auto& disp = Display<ALLEGRO_DISPLAY*>::getInstance(al_create_display(H, V))->get();
    //ALLEGRO_DISPLAY* disp = al_create_display(1080, 720);
    must_init(*disp, "display");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_primitives_addon(), "primitives");
    must_init(al_install_audio(), "audio");
    must_init(al_init_acodec_addon(), "audio codecs");
    must_init(al_reserve_samples(16), "reserve samples");
    must_init(al_init_image_addon(), "imagen");

    ALLEGRO_SAMPLE* pop = al_load_sample("../sounds/floop2_x.wav");
    ALLEGRO_SAMPLE* popi = al_load_sample("../sounds/blip.wav");

    ALLEGRO_BITMAP* user_input = al_load_bitmap("../images/user.png");
    ALLEGRO_BITMAP* menu_image = al_load_bitmap("../images/menu.png");
    ALLEGRO_BITMAP* rank_image = al_load_bitmap("../images/ranking.png");
    ALLEGRO_BITMAP* maps_image = al_load_bitmap("../images/maps.png");
    ALLEGRO_BITMAP* lose_image = al_load_bitmap("../images/lose.png");
    ALLEGRO_BITMAP* win_image = al_load_bitmap("../images/win.png");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(*disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    Keyboard* k = Keyboard::get_instance();
    Mouse* m = Mouse::getInstance();
    al_start_timer(timer);


    while (1) {
        al_wait_for_event(queue, &event);
        k->update();
        if (k->is_key_down(ALLEGRO_KEY_ESCAPE))
            done = true;

        switch (event.type) {
        case ALLEGRO_EVENT_MOUSE_AXES:
            m->move(event.mouse);
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:


            for (auto const e : v.getVista()) {
                if (e->is_on_bound()) {
                    e->click_event();
                }
            }
            break;

        case ALLEGRO_EVENT_KEY_DOWN:

            for (auto const e : v.getVista()) {
                if (e->is_press_key())
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

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue)) {
            al_clear_to_color(al_map_rgb(0, 0, 0));

            if (v.currentView() == 1) {
                al_draw_bitmap(user_input, 0, 0, 0);
            }
            else if (v.currentView() == 2) {
                al_draw_bitmap(menu_image, 0, 0, 0);
            }
            else if (v.currentView() == 4) {
                al_draw_bitmap(rank_image, 0, 0, 0);
            }
            else if (v.currentView() == 5) {
                al_draw_bitmap(maps_image, 0, 0, 0);
            }
            else if (v.currentView() == 6) {
                if (v.get_win())
                    al_draw_bitmap(win_image, 0, 0, 0);
                else {
                    al_draw_bitmap(lose_image, 0, 0, 0);
                }

            }

            for (auto const e : v.getVista()) {
                e->draw();
            }


            al_flip_display();
            redraw = false;
        }
    }
    al_destroy_bitmap(user_input);
    al_destroy_bitmap(menu_image);
    al_destroy_bitmap(rank_image);
    al_destroy_bitmap(maps_image);
    al_destroy_bitmap(lose_image);
    al_destroy_bitmap(win_image);
    al_destroy_sample(pop);
    al_destroy_sample(popi);
    al_destroy_font(font);
    al_destroy_display(*disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}