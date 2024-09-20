#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;

  int cont = 0;
  for (int i=0; i<n; i++) {
    if(s[i] == '-') cont = max(0, cont - 1);
    else cont++;
  }
  cout << cont << endl;
}

int main() {
  int t=1;
  //cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
