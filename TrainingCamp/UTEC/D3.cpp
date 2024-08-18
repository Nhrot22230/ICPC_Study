#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

vector<int> h(1e5 + 7, 0);
vector<ll> dp(1e5 + 7, -1);
int n, k;

ll DP(int i) {
  if(i <= 0) return 0;
  if(dp[i] != -1) return dp[i];

  ll temp = 1E18;
  for(int jmp=1; jmp <= k && (i-jmp)>=0; jmp++){
    temp = min(temp, DP(i-jmp) + abs(h[i] - h[i-jmp]));
  }
  dp[i] = temp;
  return dp[i];
}

void solve() {
  cin >> n >> k;
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
