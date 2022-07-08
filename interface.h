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
#include "label.h"
#include "bot.h"
#include "playerA.h"
#include "playerB.h"
#include<string>

#include <fstream>
#include <iterator>
#include <algorithm>
#include <utility>

using namespace std;

class interface {
    vector<std::shared_ptr<components>>* data = nullptr;
    unordered_map<int, vector<std::shared_ptr<components>>> interfaces;    //1:input, 2:menu, 3:map, 4:rank
    vector<std::shared_ptr<components>> create_input();

    vector<std::shared_ptr<components>> create_menu();

    vector<std::shared_ptr<components>> create_mapa();

    vector<std::shared_ptr<components>> create_rank();

    vector<std::shared_ptr<components>> create_input_map();

    vector<std::shared_ptr<components>> win();
    string map_name = "../maps/mapa.txt";
    char** mapa = llenar_mapa(map_name, 33, 54);
    string user;
    int H;
    int V;
    int current_v;
    bool pvp = false;
    bool is_win = false;
public:
    interface() = default;

    interface(int h, int v);

    void render_vista(int n_interface);

    vector<std::shared_ptr<components>> getVista();

    int currentView() const;

    char** llenar_mapa(const string& file, const int& x, const int& y);

    bool get_win();
};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_INTERFACE_H