#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
  int n; cin >> n;

  int cont = 0;
  while(n--) {
    int a, b, c; cin >> a >> b >> c;
    if(a + b + c >=2) cont++;
  }

  cout << cont << endl;
}

int main() {
  int t=1;
  //cin >> t;
  while(t--) solve();

  return 0;
}
