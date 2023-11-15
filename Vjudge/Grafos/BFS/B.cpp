#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0)

#define debug(x) cout << #x << " = " << x << endl
#define PII pair<int,int>
#define PLL pair<ll,ll>

using namespace std;

const int V = 1e6 + 5;
const int INF = 1e9;

vector<int> visited(V);
vector<vector<int>> grafo(V);

void __init___(){
    grafo.clear();
    visited.clear();

    grafo.resize(V);
    visited.resize(V, 0);
}

bool bfs(int source, int strength, int num){
    if(visited[source]) return false;
    visited[source] = num;
    queue<int> tour;
    tour.push(source);

    //cout << source << endl;

    while(not tour.empty() && strength){
        int cur_lvl = tour.size();
        
        while(cur_lvl > 0){
            int u = tour.front(); tour.pop();
            for(int v : grafo[u]){
                if(visited[v] == num) continue;
                if(visited[v] && visited[v] != num) return false;
                visited[v] = num;
                //cout << v << " ";
                tour.push(v);
            }
            //cout << endl;
            cur_lvl--;
        }
        strength--;
    }

    return true;
}

void solve(){
    __init___();
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        /* code */
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    bool flag_optimo = true;
    for(int i=0; i<r; i++){
        int k, s;
        cin >> k >> s;
        flag_optimo = bfs(k, s, i+1) && flag_optimo;
    }
    if(not flag_optimo){
        cout << "No" << endl;
        return;
    }

    for(int i=1; i<=n; i++) flag_optimo = flag_optimo && visited[i];
    if(not flag_optimo){
        cout << "No" << endl;
        return;
    }
    //for(int i=1; i<=n; i++) cout << i << "->" << visited[i] << endl;

    cout << "Yes" << endl;
}

int main(int argc, const char** argv) {
    fastio;
    int t=1;
    cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
    
    return 0;
}