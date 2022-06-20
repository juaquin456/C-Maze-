//
// Created by juaquin on 22/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_DISPLAY_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_DISPLAY_H

#include <memory>

template<typename T>
class Display {
    std::shared_ptr<T> data{};
    inline static Display<T> *instance = nullptr;

    template<typename ...Params>
    Display(Params ...params): data(std::make_shared<T>(params...)) {}

public:
    template<typename ...Params>
    static Display<T> *getInstance(Params ...params) {
        if (instance == nullptr) instance = new Display<T>(params...);
        return instance;
    }

    std::shared_ptr<T> &get() {
        return data;
    }
};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_DISPLAY_H
