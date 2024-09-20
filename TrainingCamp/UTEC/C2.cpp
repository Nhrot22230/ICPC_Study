#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

vector<ll> memo;

void init() {
  ll sum = 0;
  ll change = 1;
  while(sum < (int)(1e9 + 7)) {
    sum += change;
    change++;
    memo.push_back(sum);
  }
}

void solve() {
  int coins; cin >> coins;

  auto it = upper_bound(memo.begin(), memo.end(), coins);
  cout << it - memo.begin() << endl;
}

int main() {
  init();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
