//
// Created by leandro on 11/06/22.
//

#include "player.h"
#include <allegro5/allegro_font.h>

int player::ale_x() {
    int iSecret;

    iSecret = rand() % 55 + 1;
    return iSecret;
}

player::player(int c, int x, int y, ALLEGRO_COLOR color, int xs, int ys) : cantidad_items(c), x(x), y(y), a(color), x_score(xs), y_score(ys),
                                                                           components(0,0,0,0) {
    char **map = llenar_mapa("mapa.txt",33,55);

    for(int i=0;i<33;i++){
        for(int j=0;j<55;j++){
            mapa[i][j] = map[i][j];
        }

    }
}

void player::draw() {
    al_draw_filled_rectangle(x-5, y-5, x + 5, y + 5, a);
    for(auto [k, v]:items){
        v.draw();
    }
    al_draw_textf(al_create_builtin_font(), al_map_rgb(255,255,255), x_score, y_score, 1, "puntos: %d", puntos);
    move();
}

void player::alter_map() {
    int c=0;
    int p = 2;
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

char **player::llenar_mapa(const string &file, int x, int y) {
    ifstream archivo(file);
    char** array;
    array = new char*[x];
    string linea;
    int w = 0;

    for (int h = 0; h < x; h++)
    {
        array[h] = new char[y];
        getline(archivo,linea);
        w = 0;

        for(char k:linea){
            array[h][w] =k;
            w++;
        }
    }


    return array;
}
