//
// Created by juaquin on 29/05/22.
//

#ifndef PROYECTO_FINAL_PROYECTO_GRUPO6_INTERFACE_H
#define PROYECTO_FINAL_PROYECTO_GRUPO6_INTERFACE_H

#include <vector>
#include <unordered_map>
#include <memory>
#include <functional>
#include "components.h"
#include "button.h"
#include "block.h"
#include "textbox.h"
#include "player.h"
#include "label.h"

using namespace std;

class interface {
    int H;
    int V;
    vector<std::shared_ptr<components>> *data = nullptr;
    int current_v;
    unordered_map<int, vector<std::shared_ptr<components>>> interfaces;    //1:input, 2:menu, 3:map, 4:rank

    vector<std::shared_ptr<components>> create_input();

    vector<std::shared_ptr<components>> create_menu();

    vector<std::shared_ptr<components>> create_mapa();

    vector<std::shared_ptr<components>> create_rank();
public:
    interface() = default;
    interface(int h, int v);
    void render_vista(int n_interface);
    vector<std::shared_ptr<components>> getVista();
    int get_vista() const;

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_INTERFACE_H
