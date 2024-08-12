#include <bits/stdc++.h>
using namespace std;

void solve(string &s, string &t) {
  int cant = 0, ans = 0;
  for(int i=0; i<s.length(); i++) {
    if (s[i] != t[i]) cant++;
    else if (cant) {
      cant = 0;
      ans++;
    }
  }
  if (cant) ans++;
  cout << ans << endl;
}

int main() {
  string s, t;
  while(cin >> s >> t && s[0] != '*') solve(s, t);
  return 0;
}
