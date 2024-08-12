#include <bits/stdc++.h>
using namespace std;

const int N_INF = -1000000000;
const int INF = 1000000000;
typedef long long ll ;

typedef struct {
  vector<ll> dist;
  vector<int> path;
} Dijkstra;

class Graph{
  int V;
  int E;
  vector<ll> dist;
  vector<int> path;
  vector<bool> vis;

  public:
  vector<vector<pair<int, ll>>> adj;

  Graph(int n, int e) {
    V = n + 1;
    E = e;
    adj = vector<vector<pair<int, ll>>>(V);
  }

  void readGraph() {
    int e = E;
    while(e--) {
      int u, v, w;
      cin >> u >> v >> w;

      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
  }

  Dijkstra dijkstra(int src) {
    dist = vector<ll>(V, INF);
    path = vector<int>(V, -1);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<int, ll>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
      int from = pq.top().second;
      int d = pq.top().first;
      pq.pop();
      for (auto &neighbor : adj[from]) {
        int v = neighbor.first;
        int w = neighbor.second;
        if (dist[v] > dist[from] + w) {
          dist[v] = dist[from] + w;
          path[from] = v;
          pq.push({dist[v], v});
        }
      }
    }

    return {dist, path};
  }

  vector<int> restore_path(int src, int to, vector<int> const& p) {
    vector<int> path;
    for (int v = to; v != src; v = p[v]) path.push_back(v);
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
  }
};

void solve() {
  int n; cin >> n;
  Graph g(n, n);

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      int num;
      cin >> num;
      if(i == j) continue;

      g.adj[i].push_back({j, num});
    }
  }

  vector<vector<ll>> d_from(n);
  for(int i=0; i<n; i++) {
    Dijkstra dd = g.dijkstra(i);
    d_from[i] = dd.dist;
  }

  ll sum = 0;
  int r; cin >> r;
  while(r--) {
    int from, to;
    cin >> from >> to;
    from--;
    to--;
    sum += d_from[from][to];
  }

  cout << sum << endl;
}

int main() {
  int t = 1;
  cin >> t;

  int cont = 1;
  while(t--) {
    cout << "Case #" << cont << ": ";
    solve();
    cont++;
  }
}
