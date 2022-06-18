//
// Created by juaquin on 29/05/22.
//

#include <fstream>
#include <iterator>
#include <map>
#include <algorithm>
#include "interface.h"

void interface::render_vista(int n_interface) {
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
                interfaces.insert({n_interface, create_rank()});
                break;
        }
    }
    current_v = n_interface;
    data = &interfaces.at(n_interface);
}

vector<std::shared_ptr<components>> interface::getVista() {
    return *data;
}

int interface::get_vista() const {
    return current_v;
}

vector<std::shared_ptr<components>> interface::create_input() {
    vector<std::shared_ptr<components>> temp;
    function<void()> f = [this](){this->render_vista(2);};
    temp.push_back(make_shared<textbox>("", 440, 320, 640, 400, f));
    return temp;
}

vector<std::shared_ptr<components>> interface::create_menu() {
    vector<std::shared_ptr<components>> temp;
    function<void()> f1_rank = [this](){this->render_vista(4);};
    function<void()> f2_play = [this](){this->render_vista(3);};
    function<void()> f3_custom = [this](){this->render_vista(5);};
    temp.push_back(make_shared<button>("RANKING", 230, 320, 430, 400,f1_rank));
    temp.push_back(make_shared<button>("JUGAR", 440, 320, 640, 400,f2_play));
    temp.push_back(make_shared<button>("PERZONALIZAR", 650, 320, 850, 400,f3_custom));
    return temp;
}

vector<std::shared_ptr<components>> interface::create_mapa() {
    vector<std::shared_ptr<components>> temp;

    char mapa[20][32]= {"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
                        "x                             x",
                        "x                             x",
                        "x   xx xxxxxxx    x            ",
                        "xx x x x x  xxxxxxx            ",
                        "x          x xxxxxx            ",
                        "x x xxxx xxxx    xx            ",
                        "x x xxxx xxxx xxxxx            ",
                        "xxxxxx          xxx            ",
                        "xx       xxx  xxx x            ",
                        "xx  xxxxxxxx   x xx           ",
                        "xxx    xxxxxxxxx xx           ",
                        "xx  xxxx          x           ",
                        "xx  x    xxxxxxxxxx           ",
                        "x       xxxxxxxxxxx           ",
                        "xx   xxx          x           ",
                        "xx         xxxxxxxx           ",
                        "xxx xxxxxx   xxxxxx           ",
                        "x x xxxxxxxx   xxxx           ",
                        "xxxxxxxxxxxxxxxxxxx xxxxxxxx  "};

    for(int i=0; i<20; i++) {
        for (int j = 0; j < 32; j++) {
            if (mapa[i][j] == 'x') {
                temp.push_back(make_shared<block>(j * 20, i * 20, (j + 1) * 20 - 3, (i + 1) * 20 - 3));
            }
        }
    }



    return temp;
}

vector<std::shared_ptr<components>> interface::create_rank() {
    vector<std::shared_ptr<components>> temp;
    temp.push_back(make_shared<label>("User",H/2 - 100,20, H/2-50,60));
    temp.push_back(make_shared<label>("Score",H/2+50,20, H/2+100,60));
    ifstream f("../rank");
    if(f.is_open()){
        map<string,string> datos;
        string name;
        string score;
        int c = 0;
        for(auto it = istream_iterator<string>(f); it !=istream_iterator<string>(); it++){
            cout << *it << endl;
            if(c%2==0){
                if(c!=0){
                    datos.insert({name, score});
                }
                name = *it;
            }
            else{
                score = *it;
            }
            c++;
        }
        datos.insert({name, score});
        int i = 0;
        for(auto&[a,b]: datos){
            cout << a << "\t" << b << endl;
            const char * t_name = a.c_str();
            const char * t_score = b.c_str();
            temp.push_back(make_shared<label>(a.c_str(),H/2 - 100,100+i*20, H/2-50,120+i*20));
            temp.push_back(make_shared<label>(t_score,H/2+50,100+i*20, H/2+100,120+i*20));
            i++;
        }
    }

    return temp;
}

interface::interface(int h, int v) : H(h), V(v) {}
