#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;

void solve() {
  int n;
  cin >> n;
  vector<int> stores(n);
  for(int i = 0; i < n; i++) cin >> stores[i];
  int q;
  cin >> q;
  sort(stores.begin(), stores.end());

  while(q--) {
    int budget;
    cin >> budget;
    auto it = upper_bound(stores.begin(), stores.end(), budget);
    int index = it - stores.begin();
    cout << index << endl;
  }
}

int main() {
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
