#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

void Solve(string s){
  vector<long long> divisors(25);
  if (s[0] == 'N') {
    cout << "-1\n";
    return;
  }

  long long ans = 1;
  for (long long i=2; i<=(long long)s.length(); ++i) {
    if (s[i-1] == 'Y') ans = (ans * i)/gcd(ans, i);
  }

  for (long long i=2; i<=(long long)s.length(); ++i) {
    if (s[i-1] == 'N' && ans % i == 0) {
      cout << -1 << "\n";
      return;
    }
  }
  cout << ans << endl;
}

int main() {
  string t = "ga";
  while (true) {
    cin >> t;
    if (t[0] == '*') break;
    Solve(t);
  }
  return 0;
}
