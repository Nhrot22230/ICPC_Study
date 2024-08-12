#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; cin >> n;

  string s1; cin >> s1;
  string s2; cin >> s2;

  for(int i = 0; i < n; i++) {
    if (s1[i] == s2[i]) continue;
    else if (s1[i] == 'G' && s2[i] == 'B') continue;
    else if (s1[i] == 'B' && s2[i] == 'G') continue;
    else {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
