#include <bits/stdc++.h>

using namespace std;

const int V = 100;


bool visitados[V] {}; 
vector<vector<int> > grafo;

void detector_bucles(int nodo, int anterior, int &cont){
    
    if(visitados[nodo]) {
        cont++;
        return;
    }
    
    visitados[nodo] = true;
    for(int v: grafo[nodo]){
        if(v == anterior) continue;
        detector_bucles(v, nodo, cont);
    }

}

int main(){
    int n, m;
    cin >> n >> m;
    grafo.resize(n + 2);
    while(m--){
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    
    int cont = 0;
    detector_bucles(1, 0, cont);
    bool allVisited = true;

    for(int i=1; i<=n; i++){
        allVisited = allVisited && visitados[i];
    }

    if(cont == 2 && allVisited){
        cout << "FHTAGN!" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}