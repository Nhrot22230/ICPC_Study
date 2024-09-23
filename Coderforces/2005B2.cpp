#include <bits/stdc++.h>
#include <cmath>
#define ll long long
using namespace std;

void solve(){
  int n, m, q; cin >> n >> m >> q;
  vector<ll> t_pos(m,0);
  for (ll &i : t_pos) cin >> i;
  sort(t_pos.begin(), t_pos.end());

  while(q--) {
    ll d; cin >> d;
    auto t_r = upper_bound(t_pos.begin(), t_pos.end(), d);

    ll left_s = 0;
    if (t_r == t_pos.begin()) {
      left_s = -1;
    } else {
      left_s = *(t_r - 1);
    }

    ll right_s = n;
    if (t_r == t_pos.end()) {
      right_s = -1;
    }
    else {
      right_s = *t_r;
    }

    ll ans = 0;
    if (left_s == -1) {
      ans = right_s - 1;
    }
    else if (right_s == -1) {
      ans = n - left_s;
    }
    else {
      ans = (right_s - left_s) / 2LL;
    }

    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  cin >> t;
  while (t--) {
    solve();
  }
}
