#include <bits/stdc++.h>
using namespace std;

string words[10000 + 7];

void solve(){
  int n;
  cin >> n;

  for(int i=0; i<n; i++) cin >> words[i];
  sort(words, words + n);

  for(int i=1; i<n; i++){
    if (words[i-1].length() > words[i].length()) continue;
    bool flag = true;
    for (int k=0; k<words[i-1].length(); k++) {
      flag = flag && (words[i-1][k] == words[i][k]);
    }
    if (flag) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

int main() {
  int t = 1;
  cin >> t;
  while(t--) solve();

  return 0;
}
