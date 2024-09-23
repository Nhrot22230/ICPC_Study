#include<bits/stdc++.h>
using namespace std;

int calc(int numZeros, int k) {
  return (numZeros + k) / (1 + k);
}

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;

  for(int i=0; i<n; i++) {
    if (s[i] == '1') {
      for(int j = max(0, i - k); j < n && j <= (i + k); j++)
      if(s[j] == '0') s[j] = '-';
    }
  }

  int cont = 0;
  int ans = 0;
  for(int i=0; i<n; i++) {
    if(s[i] != '0') {
      ans += calc(cont, k);
      cont = 0;
    }
    else cont++;
  }
  if (s[n-1] == '0') ans += calc(cont, k);
  cout << ans << endl;
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
