#pragma once

#include<vector>
#include<iostream>
#include<queue>
#include<map>
#include<algorithm>

#define ii pair<int, int>
#define f first
#define s second
#define N 55

using namespace std;


void bfs(char A[][N], int index, vector<pair<int, int>> cities);

int tsp(pair<int, int> init, int pos, int visited, vector<vector<int>> &state, vector<vector<int>> &parent, int cont,
        vector<pair<int, int>> cities);

void init(char mapa[][N], int n, int m, vector<pair<int, int>> &cities);

vector<pair<int, int>> getPath(pair<int, int> begin, char mapa[][N], int n, int m);