#include <bits/stdc++.h>
using namespace std;

int reversed(int number) {
  int ans = 0;
  while (number > 0) {
    int digit = number%10;
    ans = ans*10 + digit;
    number /= 10;
  }

  return ans;
}

void solve() {
  int a, b, c;
  cin >> a >> b;
  a = reversed(a);
  b = reversed(b);
  c = a + b;
  cout << reversed(c) << endl;
}

int main() {
  int t=1; cin >> t;
  while(t--) solve();
  return 0;
}
