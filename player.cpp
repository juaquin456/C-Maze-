//
// Created by leandro on 11/06/22.
//

#include "player.h"
#include <allegro5/allegro_font.h>

int player::ale_x() {
    int iSecret;

    iSecret = rand() % 30 + 1;
    return iSecret;
}

player::player(int c, int x, int y, ALLEGRO_COLOR color, int xs, int ys) : cantidad_items(c), x(x), y(y), a(color), x_score(xs), y_score(ys) {}

void player::draw() {
    al_draw_filled_rectangle(x-5, y-5, x + 5, y + 5, a);
    for(auto [k, v]:items){
        v.draw();
    }
    al_draw_textf(al_create_builtin_font(), al_map_rgb(255,255,255), x_score, y_score, 1, "puntos: %d", puntos);
}

void player::alter_map() {
    int c=0;
    int p =2;
    while(c < cantidad_items){
        int i = ale_x();

        if(mapa[p][i]!='x'&&mapa[p][i]!='O'){
            mapa[p][i]='#';
            items.insert({p*55+i, item(i*20+8, p*20+8, a)});
            c++;
            p+=2;
        }
    }

}
