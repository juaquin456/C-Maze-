#include<vector>
#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
#define ii pair<int, int>
#define f first
#define s second
#define INT_MAX 1e9
using namespace std;
const int N=20;
bool vis[N][N];
int previousStep[N][N][N];
             //arr der aba  izq
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dist[N][N][N];

void bfs(char A[][N], int index, vector<pair<int,int>> cities) {
    int n=20,m=20,cont=7;
    queue<pair<int,int>> q;
    pair<int,int> begin = cities[index];
    q.push(begin);
    vis[begin.f][begin.s] = true;
    while (!q.empty()) {
        ii u = q.front(); q.pop();
        //if (A[u.f][u.s] == '#') cont--; 
        
        for (int i = 0; i < 4; i++) {
            ii v = {u.f + dx[i], u.s + dy[i]};
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



int tsp(pair<int,int> init, int pos, int visited, vector<vector<int>>& state, vector<vector<int>>& parent, int  cont, vector<pair<int,int>> cities)
{

    if(visited == ((1 << cont) - 1))
        return dist[init.f][init.s][pos]; // volver a la ciudad de partida

    if(state[pos][visited] != INT_MAX)
        return state[pos][visited];

    int ans = INT_MAX;

    for(int i = 0; i < cont; ++i){
        // no podemos visitarnos a nosotros mismos a menos que estemos terminando y omitir si ya lo visitamos
        if(i == pos || (visited & (1 << i)) != 0)
            continue;

        int distance = dist[cities[i].f][cities[i].s][pos] + tsp(init, i, visited | (1 << i), state, parent, cont, cities);
        if(distance < ans){
            ans = distance;
            parent[pos][visited] = i;
        }
    }

    return state[pos][visited]=ans;

}


void init(char mapa[][N], int n, int m, vector<pair<int,int>> &cities){
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            for(int k=0;k<n;k++)
                previousStep[i][j][k]= 4;

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (mapa[i][j]=='#')
               cities.push_back({i, j});

    for (int i = 0; i < cities.size(); i++){
        bfs(mapa, i, cities);
        // for(int j = 0; j < n; j++){
        //     for(int k = 0; k < m; k++){
        //         cout<<dist[j][k][i]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                vis[j][k]=false;
            }
        }
        // cout<<cities[i].f<<" "<<cities[i].s<<endl;
        // for(int j = 0; j < n; j++){
        //     for(int k = 0; k < m; k++){
        //         cout<<previousStep[j][k][i]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"***************************"<<endl;
    }

}
int main(){
    int n=20, m=20;
    char mapa[20][20]= {"xxxxxxxxxxxxxxxxxxx",
                        "x x  x  #  x      x", // (1,8)
                        "x x xx xxx   xxxx x",
                        "x   xx xxxxxxx    x",
                        "xx x x x x  xxxxxxx",
                        "x    #     x xxxxxx", // (5,5)
                        "x x xxxx xxxx #  xx", // (6,14)
                        "x x xxxx xxxx xxxxx",
                        "xxxxxx          xxx",
                        "xx    #  xxx  xxx x", // (9,6)
                        "xx  xxxxxxxx     xx",
                        "xxx    xxxxxxxxx xx",
                        "xx  xxxx    #     x", // (12,12)
                        "xx  x    xxxxxxxxxx", 
                        "x   #   xxxxxxxxxxx", // (14,4)
                        "xx   xxx     #    x", // (15,13)
                        "xx         xxxxxxxx",
                        "xxx xxxxxx   xxxxxx",
                        "x x xxxxxxxx   xxxx",
                        "xxxxxxxxxxxxxxxxxxx"
                };

    vector<pair<int,int>> cities;

    init(mapa, n, m, cities);
    map<pair<int,int>,int> ids;
    for(int i = 0; i < cities.size(); i++)
        ids[cities[i]] = i;

    int cont = cities.size();
 
    vector<vector<int>> state(n, vector<int>(1 << n, INT_MAX));
    vector<vector<int>> parent(n, vector<int>(1 << n, 0));
    pair<int,int> init = cities[0];
    cout << tsp(init, 0, 1, state, parent, cont, cities) << endl;
    vector<pair<int,int>> camino;
    // find path tsp
    int pos = 0;
    int visited = 1;
    while(visited != (1 << cont) - 1){
        camino.push_back(cities[pos]);
        int next = parent[pos][visited];
        visited |= (1 << next);
        pos = next;
    }
    camino.push_back(cities[pos]);

    int sz=camino.size();
    for(int i = 0; i < sz; ++i){
        cout << camino[i].f << " " << camino[i].s << endl;
    }
    cout<<"***************************"<<endl;
    char c='1';
    for(int i=0;i<sz;i++){
        vector<pair<int,int>> steps;
        pair<int,int> begin,end;
        if(i==sz-1){
            begin = camino[i];
            end = camino[0];
        }else {
            begin = camino[i];
            end = camino[i+1];
        }
        while (end != begin) {
            int p = previousStep[end.f][end.s][ids[begin]];
            //cout<<p<<endl;
            steps.push_back({end.f, end.s});
            end = {end.f - dx[p], end.s - dy[p]};
        }
        reverse(steps.begin(), steps.end());
        for(auto x:steps){
            camino.push_back(x);
            //mapa[x.f][x.s]=c;
            cout<<x.f<<" "<<x.s<<endl;
        }
        cout<<steps.size()<<endl;
        cout<<"***************************"<<endl;
        //c++;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<mapa[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
    
}