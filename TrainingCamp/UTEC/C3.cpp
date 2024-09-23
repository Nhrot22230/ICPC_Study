#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

vector<int> h(1e5 + 7, 0);
vector<ll> dp(1e5 + 7, -1);
int n;

ll DP(int i) {
  if(i <= 0) return 0;
  if(dp[i] != -1) return dp[i];

  if (i >= 2)
    dp[i] = min(
      DP(i - 1) + abs(h[i] - h[i - 1]),
      DP(i - 2) + abs(h[i] - h[i - 2])
    );
  else
    dp[i] = DP(i - 1) + abs(h[i] - h[i - 1]);
  return dp[i];
}

void solve() {
  cin >> n;
  for(int i=0; i<n ; i++) cin >> h[i];
  cout << DP(n - 1) << endl;
}

int main() {
  int t=1;
  //cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
