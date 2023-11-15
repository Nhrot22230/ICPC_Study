#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
 
using namespace std;
 
const int V = 2*1e5;
vector<vector<int>> grafo(V+1);
ll dp_size[V+1]{};
ll ans = 0;
 
void calc_size(int nodo, int anterior) {
    dp_size[nodo] = 1;
    for (int v : grafo[nodo]) {
        if (v == anterior) continue;
        calc_size(v, nodo);
        dp_size[nodo] += dp_size[v];
    }
}
 
void updt_max_dfs(int nodo, int anterior, ll sum, int n) {
    ans = max(ans, sum);
    for (int v : grafo[nodo]) {
        if (v == anterior) continue;
        ll tmp = sum + n - 2*dp_size[v];
        updt_max_dfs(v, nodo, tmp, n);
    }
}
 
int main() {
    int m;
    cin >> m;
    for(int i=1; i<m; i++){
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
 
    calc_size(1, 0);
    ll total = 0;
    for(int i=1; i<=m; i++) total+= dp_size[i];
    updt_max_dfs(1, 0, total, m);
    cout << ans << endl;
 
    return 0;
}