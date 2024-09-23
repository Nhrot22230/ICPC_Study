#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve() {
  string dict; cin >> dict;
  int n; cin >> n;

  vector<pair<ll, string>> words;
  while (n--) {
    string s; cin >> s;
    words.push_back({0, s});
  }

  for(int i=0; i<words.size(); i++) {
    int ptrA=0, ptrB=0;



  }

  sort(words.begin(), words.end());
  reverse(words.begin(), words.end());
  for(auto it : words) cout << it.second << ": " << it.first << endl;
}

int main() {
  int t=1;
  cin >> t;
  while (t--) {
    solve();
    if (t > 0)cout << endl;
  }
  return 0;
}
