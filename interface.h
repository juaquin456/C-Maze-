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

using namespace std;

class interface {
    vector<std::shared_ptr<components>> *data = nullptr;
    int current_v;
    unordered_map<int, vector<std::shared_ptr<components>>> interfaces;    //1:input, 2:menu, 3:map

    vector<std::shared_ptr<components>> create_input() {
        vector<std::shared_ptr<components>> temp;
        function<void()> f = [this](){this->render_vista(2);};
        temp.push_back(make_shared<textbox>("", 440, 320, 640, 400, f));
        return temp;
    }

    vector<std::shared_ptr<components>> create_menu() {
        vector<std::shared_ptr<components>> temp;
        temp.push_back(make_shared<button>("RANKING", 230, 320, 430, 400,2,3));
        temp.push_back(make_shared<button>("JUGAR", 440, 320, 640, 400,2,3));
        temp.push_back(make_shared<button>("PERZONALIZAR", 650, 320, 850, 400,2,3));
        return temp;
    }

    vector<std::shared_ptr<components>> create_mapa() {
        vector<std::shared_ptr<components>> temp;

        char mapa[20][20]= {"xxxxxxxxxxxxxxxxxxx",
                            "x x  x     x      x",
                            "x x xx xxx   xxxx x",
                            "x   xx xxxxxxx    x",
                            "xx x x x x  xxxxxxx",
                            "x          x xxxxxx",
                            "x x xxxx xxxx    xx",
                            "x x xxxx xxxx xxxxx",
                            "xxxxxx          xxx",
                            "xx       xxx  xxx x",
                            "xx  xxxxxxxx   x xx",
                            "xxx    xxxxxxxxx xx",
                            "xx  xxxx          x",
                            "xx  x    xxxxxxxxxx",
                            "x       xxxxxxxxxxx",
                            "xx   xxx          x",
                            "xx         xxxxxxxx",
                            "xxx xxxxxx   xxxxxx",
                            "x x xxxxxxxx   xxxx",
                            "xxxxxxxxxxxxxxxxxxx"};

        for(int i=0; i<20; i++) {
            for (int j = 0; j < 20; j++) {
                if (mapa[i][j] == 'x') {
                    temp.push_back(make_shared<block>(i * 35, j * 35, (i + 1) * 35 - 5, (j + 1) * 35 - 5));
                }
            }
        }

        return temp;
    }


public:
    void render_vista(int n_interface) {
        if (interfaces.find(n_interface) == interfaces.end()) {
            switch (n_interface) {
                case 1:
                    interfaces.insert({n_interface, create_input()});
                    break;
                case 2:
                    interfaces.insert({n_interface, create_menu()});
                    break;
                case 3:
                    interfaces.insert({n_interface, create_mapa()});
                    break;
                case 4:
                    interfaces.insert({n_interface, create_mapa()});
                    break;
            }
        }
        current_v = n_interface;
        data = &interfaces.at(n_interface);
    }

    vector<std::shared_ptr<components>> getVista() {
        return *data;
    }

    int get_vista() const{
        return current_v;
    }

};


#endif //PROYECTO_FINAL_PROYECTO_GRUPO6_INTERFACE_H
