#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Graph {
  ll V;
  ll E;
  vector<vector<pair<int, ll>>> adj;

public:
  Graph(int n, int e) : V(n + 1), E(e), adj(n + 1) {}

  void readGraph() {
    for (int i = 0; i < E; ++i) {
      int u, v;
      cin >> u >> v;
      u++; v++;

      adj[v].push_back({u, 1});
    }
  }

  pair<ll, ll> dfs_recursive(int src) {
    vector<bool> visited(V, false);
    return dfs_recursive_util(src, visited);
  }

private:
  pair<ll, ll> dfs_recursive_util(int node, vector<bool> &visited) {
    visited[node] = true;

    ll maxPath = 0;
    ll maxNeighbor = node;
    for (const auto &neighbor : adj[node]) {
      int v = neighbor.first;
      if (!visited[v]) {
        auto res = dfs_recursive_util(v, visited);
        if (maxPath < res.second + 1) {
          maxPath = res.second + 1;
          maxNeighbor = v;
        } else if (maxPath == res.second + 1 && maxNeighbor > res.first) {
          maxNeighbor = v;
        }
      }
    }
    return {maxNeighbor, maxPath};
  }
};

int main() {
  ll n; cin >> n;
  Graph g(1e6, n);

  g.readGraph();
  auto res = g.dfs_recursive(0);
  cout << res.second << " " << res.first - 1 << endl;
  return 0;
}
