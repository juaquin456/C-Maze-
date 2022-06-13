//
// Created by leandro on 11/06/22.
//

#include "player.h"

int ale() {
    int iSecret, iGuess;
    srand (time(NULL));
    iSecret = rand() % 700 + 100;
    return iSecret;
}
