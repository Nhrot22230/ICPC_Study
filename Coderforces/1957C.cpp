#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const ll MOD = 1e9 + 7;
vector<ll> dp(1e6, 0);

void init() {
  dp[0] = 1;
  dp[1] = 1;
  for(int i=2; i<1e6; i++) {
    dp[i] = (dp[i-1] + (2*(i-1)*dp[i-2])%MOD)%MOD;
  }
}

void solve(){
  int n, k; cin >> n >> k;
  while(k--) {
    int x, y; cin >> x >> y;
    if (x == y) n-=1;
    else n-=2;
  }
  cout << dp[n] << endl;
}

int main() {
  init();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
