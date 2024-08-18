#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;

void solve() {
  int n; cin >> n;
  vector<int> Alice(n);
  vector<int> Bob(n);

  for(int i=0; i<n; i++) cin >> Alice[i];
  for(int i=0; i<n; i++) cin >> Bob[i];

  if(Alice == Bob) {
    cout << "Bob" << endl;
    return;
  }
  reverse(Bob.begin(), Bob.end());
  if(Alice == Bob) {
    cout << "Bob" << endl;
    return;
  }
  cout << "Alice" << endl;
}

int main() {
  int t=1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
