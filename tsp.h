#pragma once

#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include <thread>
#include <mutex>

using namespace std;


void bfs(char A[][54], int index, vector<pair<int, int>> cities);

int tsp(pair<int, int> init, int pos, int visited, vector<vector<int>>& state, vector<vector<int>>& parent, int cont,
    vector<pair<int, int>> cities);

void init(char(*mapa)[54], int n, int m, vector<pair<int, int>>& cities);

vector<pair<int, int>> getPath(pair<int, int> begin, char(*mapa)[54], int n, int m);