#pragma once
#include<vector>
#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
#define ii pair<int, int>
#define f first
#define s second

using namespace std;
const int N = 55;
bool vis[N][N];
int previousStep[N][N][N];
//arr der aba  izq
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
constexpr int INF = 1e9;
int dist[N][N][N];

void bfs(char A[][N], int index, vector<pair<int, int>> cities) {
    int n = 33, m = 55, cont = 7;
    queue<pair<int, int>> q;
    pair<int, int> begin = cities[index];
    q.push(begin);
    vis[begin.f][begin.s] = true;
    while (!q.empty()) {
        ii u = q.front(); q.pop();
        //if (A[u.f][u.s] == '#') cont--;

        for (int i = 0; i < 4; i++) {
            ii v = { u.f + dx[i], u.s + dy[i] };
            if (v.f < 0 || v.f >= n || v.s < 0 || v.s >= m) continue;
            if (A[v.f][v.s] == 'x') continue;
            if (vis[v.f][v.s]) continue;
            vis[v.f][v.s] = true;
            dist[v.f][v.s][index] = dist[u.f][u.s][index] + 1;
            previousStep[v.f][v.s][index] = i;
            q.push(v);
        }
    }
}



int tsp(pair<int, int> init, int pos, int visited, vector<vector<int>>& state, vector<vector<int>>& parent, int  cont, vector<pair<int, int>> cities)
{

    if (visited == ((1 << cont) - 1))
        return 0; // no volver a la ciudad de partida

    if (state[pos][visited] != INF)
        return state[pos][visited];

    int ans = INF;

    for (int i = 0; i < cont; ++i) {
        // no podemos visitarnos a nosotros mismos a menos que estemos terminando y omitir si ya lo visitamos
        if (i == pos || (visited & (1 << i)) != 0)
            continue;

        int distance = dist[cities[i].f][cities[i].s][pos] + tsp(init, i, visited | (1 << i), state, parent, cont, cities);
        if (distance < ans) {
            ans = distance;
            parent[pos][visited] = i;
        }
    }
    return state[pos][visited] = ans;

}


void init(char mapa[][N], int n, int m, vector<pair<int, int>>& cities) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++)
                previousStep[i][j][k] = 4;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mapa[i][j] == '#')
                cities.push_back({ i, j });

    for (int i = 0; i < cities.size(); i++) {
        bfs(mapa, i, cities);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                vis[j][k] = false;
            }
        }
    }

}


vector<pair<int, int>> getPath(pair<int, int> begin, char mapa[][N], int n, int m) {

    // init
    //mapa[begin.first][begin.second] = '#';
    vector<pair<int, int>> cities;
    cities.push_back(begin);
    init(mapa, n, m, cities);
    int cont = cities.size();
    map<pair<int, int>, int> ids;
    for (int i = 0; i < cont; i++)
        ids[cities[i]] = i;
    // tsp
    vector<vector<int>> state(cont, vector<int>((long long) 1 << cont, INF));
    vector<vector<int>> parent(cont, vector<int>((long long) 1 << cont, 0));

    int ans = tsp(begin, 0, 1, state, parent, cont, cities);
    // find path tsp
    vector<pair<int, int>> camino;
    int pos = 0;
    int visited = 1;

    while (visited != (1 << cont) - 1) {
        camino.push_back(cities[pos]);
        int next = parent[pos][visited];
        visited |= (1 << next);
        pos = next;
    }
    camino.push_back(cities[pos]);
    int sz = camino.size();
    // get path
    vector<pair<int, int>> path;
    for (int i = 0; i < sz - 1; i++) {
        vector<pair<int, int>> steps;
        pair<int, int> begin, end;
        begin = camino[i];
        end = camino[i + 1];
        while (end != begin) {
            int p = previousStep[end.f][end.s][ids[begin]];
            steps.push_back({ end.f, end.s });
            end = { end.f - dx[p], end.s - dy[p] };
        }
        reverse(steps.begin(), steps.end());
        for (auto x : steps) {
            path.push_back(x);
        }
    }
    //mapa[begin.first][begin.second] = ' ';
    return path;
}