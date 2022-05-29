#include<vector>
#include<iostream>
#include<queue>
#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair
#define INT_MAX 1e9
using namespace std;
const int N=20;
bool vis[N][N];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(char A[][N], vector<vector<int>> &dist, ii begin) {
    int n=20,m=20,cont=7;
    queue<ii> q;
    q.push(begin);
    vis[begin.f][begin.s] = true;
    while (!q.empty() and cont>0) {
        ii u = q.front(); q.pop();
        if (A[u.f][u.s] == '#'){
            cont--;
        }
        for (int i = 0; i < 4; i++) {
            ii v = mp(u.f + dx[i], u.s + dy[i]);
            if (v.f < 0 || v.f >= n || v.s < 0 || v.s >= m) continue;
            if (A[v.f][v.s] == 'x') continue;
            if (vis[v.f][v.s]) continue;
            vis[v.f][v.s] = true;
            dist[v.f][v.s] = dist[u.f][u.s] + 1;
            //previousStep[v.f][v.s] = i;
            q.push(v);
        }
    }
}


/*
Dado un grafo completo, no dirigido y ponderado en forma de matriz de adyacencia,
devuelve el recorrido más pequeño que visita todos los nodos y comienza y termina en el mismo
nodo. Esta solución de programación dinámica se ejecuta en O(n^2 * 2^n).
El costo mínimo para completar el tour.
*/
int tsp(const vector<vector<int>>& cities, int pos, int visited, vector<vector<int>>& state)
{
    if(visited == ((1 << cities.size()) - 1))
        return cities[pos][0]; // volver a la ciudad de partida

    if(state[pos][visited] != INT_MAX)
        return state[pos][visited];

    for(int i = 0; i < cities.size(); ++i)
    {
        // no podemos visitarnos a nosotros mismos a menos que estemos terminando y omitir si ya lo visitamos
        if(i == pos || (visited & (1 << i)))
            continue;

        int distance = cities[pos][i] + tsp(cities, i, visited | (1 << i), state);
        if(distance < state[pos][visited])
            state[pos][visited] = distance;
    }

    return state[pos][visited];
}

int main(){
    int n=20;
    char mapa[20][20]= {"xxxxxxxxxxxxxxxxxxx",
                        "x x  x  #  x      x",
                        "x x xx xxx   xxxx x",
                        "x   xx xxxxxxx    x",
                        "xx x x x x  xxxxxxx",
                        "x    #     x xxxxxx",
                        "x x xxxx xxxx #  xx",
                        "x x xxxx xxxx xxxxx",
                        "xxxxxx          xxx",
                        "xx    #  xxx  xxx x",
                        "xx  xxxxxxxx   x xx",
                        "xxx    xxxxxxxxx xx",
                        "xx  xxxx    #     x",
                        "xx  x    xxxxxxxxxx",
                        "x   #   xxxxxxxxxxx",
                        "xx   xxx     #    x",
                        "xx         xxxxxxxx",
                        "xxx xxxxxx   xxxxxx",
                        "x x xxxxxxxx   xxxx",
                        "xxxxxxxxxxxxxxxxxxx"
                };
    vector<vector<int>> dist(n, vector<int>(n, 0));
    bfs(mapa, dist, mp(1, 1));
    for(auto i: dist){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    // vector<vector<int>> cities(n, vector<int>(n, 0));
    // for(int i = 0; i < n; ++i)
    //     for(int j = 0; j < n; ++j)
    //         cin >> cities[i][j];
            

    // vector<vector<int>> state(n, vector<int>(1 << n, INT_MAX));
    // cout << tsp(cities, 0, 1, state) << endl;
}