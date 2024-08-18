#include <bits/stdc++.h>
#define ll unsigned long long
#define endl '\n'
using namespace std;

void solve() {
  int q, k; cin >> q >> k;
  unordered_map<string, ll> friends;
  while(q--){
    string f; cin >> f;
    ll m; cin >> m;
    friends[f];
    friends[f] += m;
  }
  vector<ll> spare;
  for(auto it : friends) spare.push_back(it.second);
  sort(spare.begin(), spare.end());
  reverse(spare.begin(),spare.end());

  ll ans = 0;
  for(ll ga : spare) {
    if(k == 0) break;
    ans += ga;
    k--;
  }
  cout << ans << endl;
}

int main() {
  int t=1;
  //cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
