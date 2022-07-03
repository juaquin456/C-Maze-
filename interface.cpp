//
// Created by juaquin on 29/05/22.
//

#include <fstream>
#include <iterator>
#include <unordered_map>
#include <algorithm>
#include<ctime>
#include "interface.h"


char** interface::llenar_mapa(const string& file, int x, int y) {
    ifstream archivo(file);
    char** array1;
    array1 = new char* [x];
    string linea;
    int w = 0;

    for (int h = 0; h < x; h++) {
        array1[h] = new char[y];
        getline(archivo, linea);
        w = 0;

        for (char k : linea) {
            array1[h][w] = k;
            w++;
        }
    }


    return array1;
}

void interface::render_vista(int n_interface) {
    if (interfaces.find(n_interface) == interfaces.end()) {
        switch (n_interface) {
        case 1:
            interfaces.insert({ n_interface, create_input() });
            break;
        case 2:
            interfaces.insert({ n_interface, create_menu() });
            break;
        case 3:
            interfaces.insert({ n_interface, create_mapa() });

            break;
        case 4:
            interfaces.insert({ n_interface, create_rank() });
            break;
        }
    }
    current_v = n_interface;
    data = &interfaces.at(n_interface);
}

vector<std::shared_ptr<components>> interface::getVista() {
    return *data;
}

int interface::currentView() const {
    return current_v;
}

vector<std::shared_ptr<components>> interface::create_input() {
    vector<std::shared_ptr<components>> temp;
    function<void(string)> fun_write = [this](const string& text) {
        this->user = text;
        cout << "xd" << user << '\n';
        this->render_vista(2);
    };
    temp.push_back(make_shared<label>("Ingrese su usuario:", 440, 290, 640, 350, al_map_rgb(0, 0, 0),
        al_map_rgb(255, 255, 255)));
    temp.push_back(make_shared<textbox>("", 440, 320, 640, 400, fun_write));
    return temp;
}

vector<std::shared_ptr<components>> interface::create_menu() {
    vector<std::shared_ptr<components>> temp;
    function<void()> f1_rank = [this]() { this->render_vista(4); };
    function<void()> f2_play_pvp = [&]() {
        this->pvp = true;
        this->render_vista(3);
    };
    function<void()> f2_play_pve = [&]() {
        this->pvp = false;
        this->render_vista(3);
    };
    function<void()> f3_custom = [this]() { this->render_vista(5); };
    temp.push_back(make_shared<button>("JUGAR PVP", 440, 170, 640, 260, f2_play_pvp));
    temp.push_back(make_shared<button>("JUGAR PVE", 440, 270, 640, 360, f2_play_pve));
    temp.push_back(make_shared<button>("RANKING", 440, 370, 640, 460, f1_rank));
    temp.push_back(make_shared<button>("PERZONALIZAR", 440, 470, 640, 560, f3_custom));
    return temp;
}

vector<std::shared_ptr<components>> interface::create_mapa() {
    vector<std::shared_ptr<components>> temp;

    int x = 33;
    int y = 55;
    char** mapa = llenar_mapa("mapa.txt", 33, 55);

    for (int i = 0; i < 33; i++) {
        for (int j = 0; j < 55; j++) {
            if (mapa[i][j] == 'x') {
                temp.push_back(make_shared<block>(j * 20, i * 20, (j + 1) * 20 - 3, (i + 1) * 20 - 3));
            }
        }
    }
    clock_t tiempo = clock();
    temp.push_back(make_shared<playerA>(9, 100, 100, al_map_rgb(255, 0, 0), 100, 675, mapa,tiempo,this->user));
    cout << pvp << endl;
    if (pvp)
        temp.push_back(make_shared<playerB>(9, 28, 28, al_map_rgb(255, 255, 0), 700, 675, mapa,tiempo,this->user));
    else
        temp.push_back(make_shared<bot>(9, 28, 28, al_map_rgb(255, 255, 0), 700, 675, mapa,tiempo,this->user));
    
    return temp;
}

vector<std::shared_ptr<components>> interface::create_rank() {
    
    vector<std::shared_ptr<components>> temp;
    temp.push_back(make_shared<label>("User", H / 2 - 100, 20, H / 2 - 50, 60,
        al_map_rgb(255, 255, 255), al_map_rgb(0, 0, 0)));
    temp.push_back(make_shared<label>("Score", H / 2 + 50, 20, H / 2 + 100, 60,
        al_map_rgb(255, 255, 255), al_map_rgb(0, 0, 0)));
    ifstream f("rank");
    if (f.is_open()) {
        unordered_map<string, string> datos;
        vector<pair<string, string>> new_datos;
        string name;
        string score;
        int c = 0;
        for (auto it = istream_iterator<string>(f); it != istream_iterator<string>(); it++) {
            if (!(c&1)) name = *it;
            else {
                score = *it;
                int temp2 = stoi(score);
                int temp1 = temp2;
                if(datos[name] != "") temp1 = stoi(datos[name]);
                int result = min(temp1, temp2);
                datos[name] = to_string(result);
            }
            c++;
        }
        for (auto i : datos) {
            new_datos.push_back(i);
        }
        sort(new_datos.begin(), new_datos.end(), [] (pair<string,string> & a, pair<string, string>& b) {
            return a.second < b.second;
        });

        int i = 0;
        for (auto& [a, b] : new_datos) {
            const char* t_name = a.c_str();
            const char* t_score = b.c_str();
            temp.push_back(make_shared<label>(a.c_str(), H / 2 - 100, 100 + i * 20, H / 2 - 50, 120 + i * 20,
                al_map_rgb(0, 0, 0), al_map_rgb(255, 255, 255)));
            temp.push_back(make_shared<label>(t_score, H / 2 + 50, 100 + i * 20, H / 2 + 100, 120 + i * 20,
                al_map_rgb(0, 0, 0), al_map_rgb(255, 255, 255)));
            i++;
        }
    }
    function<void()> fn = [this]() { this->render_vista(2); };
    temp.push_back(make_shared<button>("Retroceder", 840, 600, 1000, 650, fn));

    return temp;
}

interface::interface(int h, int v) : H(h), V(v) {}
