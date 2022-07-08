//
// Created by juaquin on 22/05/22.
//

#include "Mouse.h"

Mouse* Mouse::getInstance() {
    if (instance == nullptr) instance = new Mouse();
    return instance;
}

Mouse::Mouse() {

}