#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0)

#define debug(x) cout << #x << " = " << x << endl
#define PairLL pair<ll,ll>

using namespace std;

const int V = 2*1e5 + 1;
const ll INF = 1e15;

int n_vertices, m_edges;

vector<vector<PairLL>> adj;
vector<ll> distances;
vector<ll> padres;


void __init__(){
    padres.clear();
    adj.clear();
    distances.clear();

    padres.resize(n_vertices, INF);
    adj.resize(n_vertices);
    distances.resize(n_vertices, INF);
}

void Add(ll from, ll to, ll weight){
    adj[from].push_back({weight, to});
    adj[to].push_back({weight, from});
}

void Dijkstra(ll source, ll ignored = -1){
    for(int i=0; i < n_vertices; i++) distances[i] = INF;
    
    distances[source] = 0;
    priority_queue<PairLL, vector<PairLL>, greater<PairLL> > tour;
    padres[source] = source;
    tour.push({0LL, source});
    while (!tour.empty())
    {
        PairLL path = tour.top(); tour.pop();
        int u = path.second;
        if(distances[u] != path.first) continue;

        for(PairLL edge : adj[u]){
            ll v = edge.second;
            if(v == ignored) continue;
            ll w = edge.first;
            ll d = distances[u] + w;
            if(d < distances[v]){
                padres[v] = u;
                distances[v] = d;
                tour.push({distances[v], v});
            }
        }
    }
    
}


void printPath(int source, int target){
    if(source == padres[target]) {
        cout << source + 1 << " ";
    }
    else printPath(source, padres[target]);
    cout << target + 1 << " ";
}

void Solve(){
    cin >> n_vertices >> m_edges;
    __init__();
    int source = 0, target = n_vertices - 1;

    for(int i=0; i < m_edges; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        Add(u, v, w);
    }

    Dijkstra(source);

    if(distances[target] == INF){
        cout << "-1" << endl;
        return;
    }

    printPath(source, target);
    cout << endl;
}

int main(void)
{
    fastio;
    int t=1;
    //cin >> t;
    while (t--)
    {
        /* code */
        Solve();
    }
    
    return 0;
}
