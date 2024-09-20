#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int MOD = 1E8 + 7;

void solve() {
  int t;
  cin>>t;
  int size = 5*100000 +1;
  int dp[size];
  dp[0] = dp[1] = 1;
  for(int i=2; i<size; i++){
    dp[i] = (dp[i-1] + dp[i-2])%MOD;
  }

  while(t--){
    int n;
    cin>>n;
    cout<<dp[n-1]<<'\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t=1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
