#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

char matriz[500][500] {};
bool visitado[250000] {};

vector< vector< pair<int, pair<int,int>> > > grafo(250000);

int k=0;

void sp_dfs(int nodo, int anterior){
    //cout << "Visitando..." << nodo << endl;
    visitado[nodo] = true;
    for(auto v: grafo[nodo]){
        if(v.first == anterior) continue;
        if(visitado[v.first]) continue;
        sp_dfs(v.first, nodo);
        if(k){
            matriz[v.second.first][v.second.second] = 'X';
            k--;
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matriz[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matriz[i][j] == '.'){
                if(i+1 < n && matriz[i+1][j] == '.') grafo[i*m + j].push_back({(i+1)*m + j, {i+1, j}});
                if(i-1>= 0 && matriz[i-1][j] == '.') grafo[i*m + j].push_back({(i-1)*m + j, {i-1, j}});
                if(j+1 < m && matriz[i][j+1] == '.') grafo[i*m + j].push_back({(i)*m + j+1, {i, j+1}});
                if(j-1>= 0 && matriz[i][j-1] == '.') grafo[i*m + j].push_back({(i)*m + j-1, {i, j-1}});
            }
        }
    }

    // for(int i=0; i<m*n; i++){
    //     cout << i << " -> ";
    //     for(auto v : grafo[i]){
    //         cout << " " << v.first << "(" << v.second.first << ", " << v.second.second << ") ";
    //     }
    //     cout << endl;
    // }

    for(int i=0; i<m*n; i++){
        if(grafo[i].size() > 0){
            sp_dfs(i,-1);
            break;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << matriz[i][j];
        }
        cout << endl;
    }
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