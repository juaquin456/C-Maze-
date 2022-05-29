//
// Created by juaquin on 29/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_INTERFACE_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_INTERFACE_H

#include <vector>
#include <unordered_map>
#include <memory>

#include "components.h"
#include "button.h"


using namespace std;

class interface {
    vector<std::shared_ptr<components>> *data = nullptr;
    unordered_map<int, vector<std::shared_ptr<components>>> interfaces;    //1:input, 2:menu, 3:map

    vector<std::shared_ptr<components>> create_input() {

    }

    vector<std::shared_ptr<components>> create_menu() {
        vector<std::shared_ptr<components>> temp;
        temp.push_back(make_shared<button>("JUGAR", 440, 320, 640, 400));
        return temp;
    }

    vector<std::shared_ptr<components>> create_mapa() {

    }

public:
    void render_vista(int n_interface) {
        if (interfaces.find(n_interface) == interfaces.end()) {
            switch (n_interface) {
                case 2:
                    interfaces.insert({n_interface, create_menu()});
                    break;
            }
        }
        data = &interfaces.at(n_interface);
    }

    vector<std::shared_ptr<components>> getVista() {
        return *data;
    }
};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_INTERFACE_H
