#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
  int k, n;
  cin >> n >> k;

  ll arr[n];
  for(int i=0; i<n; i++) cin >> arr[i];
  sort(arr, arr + n);
  k--;
  ll minDif = 1000000000;
  for(int i=k; i<n; i++) {
    minDif = min(minDif, arr[i] - arr[i - k]);
  }

  cout << minDif << endl;
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
