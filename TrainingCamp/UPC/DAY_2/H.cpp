#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N_MAX = 1e9 + 7;

set<ll> memo;

void init() {
  ll change = 6;
  ll behive_num = 1;
  while(behive_num < N_MAX) {
    memo.insert(behive_num);
    behive_num += change;
    change += 6;
  }
}

int main() {
  ll num;
  init();
  while(cin >> num && num != -1) {
    auto it = memo.find(num);
    if(it == memo.end()) cout << "N\n";
    else cout << "Y\n";
  }
}
