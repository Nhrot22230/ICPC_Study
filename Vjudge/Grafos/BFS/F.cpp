#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0)

#define debug(x) cout << #x << " = " << x << endl
#define all(v) v.begin(), v.end()
#define PLL pair<ll,ll>
#define PII pair<int,int>

using namespace std;

const int V = 2*1e5 + 1;
const ll INF = 1e14;

vector<ll> distances;
vector<vector<ll>> tiempos;
vector<vector<PLL>> grafo;
int n_vertices, m_edges;

ll bSearch(const vector<ll>& arr, ll target) {
    if(arr.size() == 0) return 0;
    ll left = 0;
    ll right = arr.size() - 1;

    ll index = -1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            index = mid;
            break;
        } else if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    if(index == -1) return 0;

    left = index;
    right = arr.size() -1;
    ll continuos_subsequence = 1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;

        if(arr[mid] == target + mid - index){
            if(mid == arr.size() - 1){
                continuos_subsequence = mid - index + 1;
                break;
            }
            if(arr[mid + 1] > arr[mid] + 1){
                continuos_subsequence = mid - index + 1;
                break;
            }
        }

        if(arr[mid] > target + mid - index){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return continuos_subsequence;
}

void __init__(){
    grafo.clear();
    distances.clear();
    tiempos.clear();

    grafo.resize(V);
    distances.resize(V, INF);
    tiempos.resize(V);
}

void Add(int from, int to, int weigth=1){
    grafo[from].push_back({weigth, to});
    grafo[to].push_back({weigth, from});
}

void Dijkstra(int source){
    distances[source] = bSearch(tiempos[source], 0);

    priority_queue<PLL, vector<PLL> , greater<PLL>> tour;
    tour.push({distances[source], source});
    
    while (not tour.empty())
    {
        PLL path = tour.top(); tour.pop();
        int u = path.second;
        for(PLL edge : grafo[u]){
            int v = edge.second;
            ll w = edge.first;
            ll d = distances[u] + w;
            d += bSearch(tiempos[v], d);
            if(d < distances[v]){
                distances[v] = d;
                tour.push({d, v});
            }
        }
    }
    
}

void solve(){
    __init__();
    cin >> n_vertices >> m_edges;
    for(int i=0; i<m_edges; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        Add(u, v, w);
    }
    for(int i=0; i<n_vertices; i++){
        int t, c;
        cin >> t;
        while (t--)
        {
            cin >> c;
            tiempos[i].push_back(c);
        }
    }
    tiempos[n_vertices-1].clear();
    Dijkstra(0);
    int target = n_vertices -1;

    if(distances[target] == INF) cout << -1 << endl;
    else cout << distances[target] << endl;
}

int main(int argc, char const *argv[])
{
    int t=1;
    while (t--)
    {
        /* code */
        solve();
    }
    
    return 0;
}
