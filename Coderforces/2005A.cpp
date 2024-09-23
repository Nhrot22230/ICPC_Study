#include <bits/stdc++.h>

using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  vector<int> freq = {0, 0, 0, 0, 0};

  for(int i=0; i<n; i++){
    freq[i%5]++;
  }

  string ans = "";
  for(int i=0; i<5; i++) {
    while(freq[i]--) {
      ans += vowels[i];
    }
  }
  cout << ans << endl;
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
