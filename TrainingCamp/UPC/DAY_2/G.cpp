#include <bits/stdc++.h>
using namespace std;

void solve(int b, int g) {
  if(b == g) {
    if (b == 0) cout << 0 << endl;
    else cout << 1 << endl;
    return;
  }
  if(g > b) swap(b, g);
  cout << (b + g)/(g + 1) << endl;
}

int main() {
  int b, g;
  while(cin >> b >> g && b != -1) solve(b, g);
  return 0;
}
