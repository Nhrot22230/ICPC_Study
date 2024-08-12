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
  vector<vector<pair<int, ll>>> adj;
  vector<ll> dist;
  vector<int> path;
  vector<bool> vis;

  public:
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

  void bfs(int src) {
    queue<int> q;
    vector<bool> visited(V, false);

    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      cout << node << " ";

      for (auto &neighbor : adj[node]) {
        int v = neighbor.first;
        if (!visited[v]) {
          q.push(v);
          visited[v] = true;
        }
      }
    }
    cout << endl;
  }

  void dfs(int src) {
    stack<int> s;
    vector<bool> visited(V, false);

    s.push(src);

    while (!s.empty()) {
      int node = s.top();
      s.pop();

      if (!visited[node]) {
        cout << node << " ";
        visited[node] = true;
      }

      for (auto &neighbor : adj[node]) {
        int v = neighbor.first;
        if (!visited[v]) {
          s.push(v);
        }
      }
    }
    cout << endl;
  }

  void dfs_recursive(int src) {
    vector<bool> visited(V, false);
    dfs_recursive_util(src, visited);
    cout << endl;
  }

  private:
  void dfs_recursive_util(int node, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";
    for (auto &neighbor : adj[node]) {
      int v = neighbor.first;
      if (!visited[v]) {
        dfs_recursive_util(v, visited);
      }
    }
  }
};

void solve(int cities, int bar, int charly, int nito, int streets) {
  Graph g(cities, streets);
  g.readGraph();

  Dijkstra d_b = g.dijkstra(bar);
  Dijkstra d_c = g.dijkstra(charly);
  Dijkstra d_n = g.dijkstra(nito);

  ll max = 0;
  for(int i=1; i<=cities; i++) {
    ll dist_bar = d_b.dist[i];
    ll dist_charly = d_c.dist[i];
    ll dist_nito = d_n.dist[i];

    if (
      (dist_bar + dist_charly == d_b.dist[charly]) &&
      (dist_bar + dist_nito == d_b.dist[nito]) &&
      (max < dist_bar)
    )
    max = dist_bar;
  }

  cout << max << ' ' << d_b.dist[charly] - max << ' ' << d_b.dist[nito] - max << '\n';
}

int main() {
  int cities, bar, charly, nito, streets;
  while(cin >> cities >> bar >> charly >> nito >> streets && cities != -1) {
    solve(cities, bar, charly, nito, streets);
  }
}
