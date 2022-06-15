//
// Created by leandro on 11/06/22.
//

#include "player.h"

int ale_x() {
    int iSecret;
    srand (time(NULL));
    iSecret = rand() % 31 + 1;
    return iSecret;
}

int ale_y() {
    int iSecret;

    iSecret = rand() % 31 + 1;
    return iSecret;

}
