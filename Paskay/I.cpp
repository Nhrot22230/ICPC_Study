#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

bool visitado[200000] {};
vector<vector<int>> grafo;
int contPaths=1;

void buscaCaminos(vector<int> &vertices){
    if(contPaths == 1e6) return;
    for(auto num : vertices){
        if(contPaths == 1e6) return;
        if(num == 1) continue;
        if(visitado[num]) continue;
        contPaths++;
        if(contPaths == 1e6) return;
        visitado[num] = true;
        //cout << num << "->";
        buscaCaminos(grafo[num]);
        visitado[num] = false;
    }
}

int main(){
    int cant_vertices, cant_lazos;
    cin >> cant_vertices >> cant_lazos;
    grafo.resize(cant_vertices + 1);

    int x, y;
    for(int i=0; i<cant_lazos; i++){
        cin >> x >> y;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }
    // for(int i=1; i<grafo.size(); i++){
    //     cout << i << ": ";
    //     for(int j=0; j<grafo[i].size(); j++){
    //         cout << grafo[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
    visitado[1] = true;
    buscaCaminos(grafo[1]);
    cout << contPaths << endl;
    return 0;
}