#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve() {
  int n; cin >> n;
  vector<ll> memo(n + 1, 0);
  vector<ll> a(n, 0);
  for(int i=0; i<n;i++) {
    cin >> a[i];
    memo[i + 1] = memo[i] + a[i];
  }

  int q; cin >> q;
  while(q--) {
    int l, r; cin >> l >> r;
    r++;

    cout << memo[r] - memo[l] << endl;
  }
}

int main() {
  int t=1;
  //cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
