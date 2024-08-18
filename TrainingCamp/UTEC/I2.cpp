#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];

  int ans;
  if (n > 1) ans = min(a[0],a[1]);
  for(int i=0; i<n - 2; i++){
    vector<int> tmp(3);
    for(int k=0; k<=2; k++) tmp[k] = a[i+k];
    sort(tmp.begin(), tmp.end());
    ans = max(ans,tmp[1]);
  }
  cout<<ans<<endl;
}

int main() {
  int t=1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
