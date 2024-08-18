#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200010];
 
void solve()
{
  int n, q;
  cin >> n >> q;
  map<ll, vector<ll>> mp;
  mp[0].push_back(0);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    a[i] ^= a[i - 1];
    mp[a[i]].push_back(i);
  }
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    if (a[r] == a[l - 1])
    {
      cout << "YES" << endl;
      continue;
    }
    int ur = *--lower_bound(mp[a[l - 1]].begin(), mp[a[l - 1]].end(), r);
    int ul = *lower_bound(mp[a[r]].begin(), mp[a[r]].end(), l);
    
    if (ur > ul) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}
