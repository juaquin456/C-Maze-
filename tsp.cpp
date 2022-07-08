//
// Created by juaquin on 30/06/22.
//
#include "tsp.h"
constexpr int INF = 1e9;
constexpr int N = 54;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool vis[N][N];
int previousStep[N][N][N];
//arr der aba  izq
int dist[N][N][N];
mutex mtx;

void bfs(char(*A)[N], int index, vector<pair<int, int>> cities) {
    lock_guard<mutex> lg(mtx);
    int n = 33, m = 54, cont = 7;
    queue<pair<int, int>> q;
    pair<int, int> begin = cities[index];
    q.push(begin);
    vis[begin.first][begin.second] = true;
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        //if (A[u.f][u.s] == '#') cont--;

        for (int i = 0; i < 4; i++) {
            pair<int, int> v = { u.first + dx[i], u.second + dy[i] };
            if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m) continue;
            if (A[v.first][v.second] == 'x') continue;
            if (vis[v.first][v.second]) continue;
            vis[v.first][v.second] = true;
            dist[v.first][v.second][index] = dist[u.first][u.second][index] + 1;
            previousStep[v.first][v.second][index] = i;
            q.push(v);
        }
    }
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            vis[j][k] = false;
        }
    }
}

int tsp(pair<int, int> init, int pos, int visited, vector<vector<int>>& state, vector<vector<int>>& parent, int cont,
    vector<pair<int, int>> cities) {

    if (visited == ((1 << cont) - 1))
        return 0; // no volver a la ciudad de partida

    if (state[pos][visited] != INF) {
        return state[pos][visited];
    }
    int ans = INF;

    for (int i = 0; i < cont; ++i) {
        // no podemos visitarnos a nosotros mismos a menos que estemos terminando y omitir si ya lo visitamos
        if (i == pos || (visited & (1 << i)) != 0)
            continue;

        int distance =
            dist[cities[i].first][cities[i].second][pos] +
            tsp(init, i, visited | (1 << i), state, parent, cont, cities);
        if (distance < ans) {
            ans = distance;
            parent[pos][visited] = i;
        }
    }
    return state[pos][visited] = ans;

}

void init(char(*mapa)[54], int n, int m, vector<pair<int, int>>& cities) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++)
                previousStep[i][j][k] = 4;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mapa[i][j] == '#')
                cities.push_back({ i, j });

    int n_hilos = cities.size();
    vector<thread> vhilos(n_hilos);

    int i = 0;
    for (auto& h : vhilos) {
        h = thread(bfs, mapa, i, cities);
        i++;
    }

    for (auto& h : vhilos) {
        h.join();
    }

}

vector<pair<int, int>> getPath(pair<int, int> begin, char(*mapa)[54], int n, int m) {

    // init
    vector<pair<int, int>> cities;
    cities.push_back(begin);
    init(mapa, n, m, cities);
    int cont = (int)cities.size();
    map<pair<int, int>, int> ids;
    for (int i = 0; i < cont; i++) {
        ids[cities[i]] = i;
    }
    // tsp
    vector<vector<int>> state(cont, vector<int>((long long)1 << cont, INF));
    vector<vector<int>> parent(cont, vector<int>((long long)1 << cont, 0));

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
            int p = previousStep[end.first][end.second][ids[begin]];
            steps.push_back({ end.first, end.second });
            end = { end.first - dx[p], end.second - dy[p] };
        }
        reverse(steps.begin(), steps.end());
        for (auto x : steps) {
            path.push_back(x);
        }
    }
    return path;
}