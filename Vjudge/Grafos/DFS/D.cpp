#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
 
using namespace std;
 
const int V = 1e5 + 1;
vector<vector<int>> grafo(V);
int arrGatos[V]{};

int cont = 0;

void dfs(int nodo, int anterior, int cant, int maxCat){
    if(cant > maxCat) return;
    
    if(nodo != 1 && grafo[nodo].size() == 1 && cant <= maxCat ) cont++;

    for(int v : grafo[nodo]){
        if(v == anterior) continue;

        if(arrGatos[v]){
            dfs(v, nodo, cant + 1, maxCat);
        }else{
            dfs(v, nodo, 0, maxCat);
        }
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> arrGatos[i];
    }

    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    // for(int i=1; i<=n; i++){
    //     cout << i << "->";
    //     for(int v : grafo[i]){
    //         cout << "  " << v;
    //     }
    //     cout << endl;
    // }

    dfs(1, 0, arrGatos[1], k);
    cout << cont << endl;
}

int main(void) {
    int t = 1;
    //cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
    
    return 0;
}