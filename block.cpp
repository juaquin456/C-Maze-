//
// Created by juaquin on 01/06/22.
//

#include "block.h"

void block::draw() {
    al_draw_filled_rectangle(x1, y1, x2, y2, a);
}
