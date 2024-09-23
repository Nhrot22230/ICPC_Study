#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> nums(n);
  set<int> s;

  for(int i=0; i<n; i++) {
    cin >> nums[i];
    s.insert(nums[i]);
  }

  while(q--) {
    int ga; cin >> ga;
    if(s.find(ga) == s.end()) {
      cout << -1 << endl;
    }
    else {
      auto it = lower_bound(nums.begin(), nums.end(), ga);
      cout << it - nums.begin() << endl;
    }
  }
}

int main() {
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
