#include <bits/stdc++.h>

using namespace std;
const int V = 2*1e5 + 1;

int arrVisited[V] {}; 
vector<vector<int> > grafo(V);

void dfs(int nodo, int anterior = 0, int cant = 0){
    arrVisited[nodo] = cant;
    for(int v: grafo[nodo]){
        if(v == anterior) continue;
        dfs(v, nodo, cant + 1);
    }
}

int main(){
    int m;
    cin >> m;
    for(int i=1; i<m; i++){
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    dfs(1);
    int maxNodo = 0, maxNum = 0;
    for(int i=1; i<=m; i++){
        if(arrVisited[i] > maxNum){
            maxNum = arrVisited[i];
            maxNodo = i;
        }
        arrVisited[i] = 0;
    }
    dfs(maxNodo);
    for(int i=1; i<=m; i++){
        if(arrVisited[i] > maxNum){
            maxNum = arrVisited[i];
            maxNodo = i;
        }
        arrVisited[i] = 0;
    }
    cout << maxNum << endl;
    return 0;
}