#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve() {
  int n; cin >> n;

  vector<ll> pos(n);
	vector<ll> vel(n);

	for(ll &i: pos) cin >> i;
	for(ll &i: vel) cin >> i;

  double l = 0, r = 1e18;

  while (r - l > 1e-6) {
    double m = (l + r) / 2;
    double left = -1e18, right = 1e18;
    for (int i = 0; i < n; i++) {
      left = max(left, pos[i] - m * vel[i]);
      right = min(right, pos[i] + m * vel[i]);
    }
    if (left <= right) r = m;
    else l = m;
  }

  cout << fixed << setprecision(10) << l << endl;
}

int main() {
  int t=1;
  //cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
