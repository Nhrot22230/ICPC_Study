#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

vector<ll> memo(1000002);

void solve() {
  int k; cin >> k;
  string s; cin >> s;
  memo[0] = 1;
  ll t=0, ans=0;
  for(int i = 0 ; i < s.length() ; i++){
    if(s[i] == '1') t++;
    if(t >= k) ans += memo[t-k];
    memo[t] ++;
  }
  cout << ans << endl;
}

int main() {
  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
