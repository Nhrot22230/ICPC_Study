#include <bits/stdc++.h>

using namespace std;
const int V = 2*1e5 + 1;

bool arrVisited[V] {}; 
vector<vector<int> > grafo(V);

int cycle_detector(int nodo, int anterior){
    if(grafo[nodo].size() > 2) return 0;
    if(arrVisited[nodo]) return 1;

    int cont = 0;
    arrVisited[nodo] = true;
    for(int v : grafo[nodo]){
        if(v == anterior) continue;
        cont += cycle_detector(v, nodo);
    }
    return cont;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    int cont = 0;
    for(int i = 1; i<=n; i++){
        if(arrVisited[i]) continue;
        cont += cycle_detector(i,0);
    }
    cout << cont/2 << endl;
    return 0;
}