#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; cin >> n;
  int badImpar=0, badPar=0;

  vector<int> nums(n);
  for(int i=0; i<n; i++) {
    cin >> nums[i];
    if( (nums[i] % 2) != (i % 2) ) {
      badImpar += (nums[i] % 2);
      badPar += (nums[i] % 2 == 0);
    }
  }

  if(badImpar != badPar){
    cout << "-1\n";
    return;
  }

  cout << badPar << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
