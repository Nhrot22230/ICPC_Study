#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int k2, k3, k5, k6;
  cin >> k2 >> k3 >> k5 >> k6;

  ll sum = 0;
  while(k2 > 0 && k5 > 0 && k6 > 0) {
    sum += 256;
    k2--; k5--; k6--;
  }

  while(k3 > 0 && k2 > 0) {
    sum += 32;
    k3--; k2--;
  }

  cout << sum << endl;
  return 0;
}
