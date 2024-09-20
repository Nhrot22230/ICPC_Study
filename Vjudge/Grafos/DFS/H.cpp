#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;


const int V = 2*1e5;
vector<vector<int>> grafo(V+1);
int arrVisitados[V+1]{};

void dfs(int nodo, int otraFeria){
    arrVisitados[nodo] += 1;
    if(nodo == otraFeria) return;
    for(int v : grafo[nodo]){
        if(arrVisitados[v]) continue;
        dfs(v, otraFeria);
    }
}

void dfs_2(int nodo, int otraFeria){
    arrVisitados[nodo] += 2;
    if(nodo == otraFeria) return;
    for(int v : grafo[nodo]){
        if(arrVisitados[v] >= 2) continue;
        dfs_2(v, otraFeria);
    }
}

void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    dfs(a,b);
    dfs_2(b,a);

    ll contA = 0, contB = 0;
    for(int i=1; i<=n; i++){
        if(arrVisitados[i] == 1) contA++;
        if(arrVisitados[i] == 2) contB++;
    }
    cout << contA * contB << endl;
    for(int i=1; i<=n; i++){
        arrVisitados[i] = 0;
        grafo[i].clear();
    }
}

int main(void) {
    int t = 1;
    cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
    
    return 0;
}