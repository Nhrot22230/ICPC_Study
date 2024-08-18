#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, q; cin >> n >> q;
  string s1, s2; cin >> s1 >> s2;
  vector<int>p1[27];
  vector<int>p2[27];
  for(int k=0; k<27; k++) {
    p1[k].resize(n + 1);
    p2[k].resize(n + 1);
  }

  for(int i = 1; i <= n; i++) {
    for(int k = 0; k < 26; k++) {
      p1[k][i] = p1[k][i - 1];
      p2[k][i] = p2[k][i - 1];
    }
    int k = s1[i - 1] - 'a';
    p1[k][i] = p1[k][i - 1] + 1;
    k = s2[i - 1] - 'a';
    p2[k][i] = p2[k][i - 1] + 1;
  }

  while(q--) {
    int l, r; cin >> l >> r;
    int sum = 0;
    for(int k=0; k<27; k++) {
      sum += abs( (p1[k][r] - p1[k][l - 1]) - (p2[k][r] - p2[k][l - 1]) );
    }
    cout << sum / 2 << endl;
  }
}

int main() {
  int t=1;
  cin >> t;
  while(t--) solve();

  return 0;
}
