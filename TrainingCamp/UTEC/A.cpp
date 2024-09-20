#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;

void solve() {
  int n, m, k;
  cin>>n>>m>>k;
  int l, r ;
  l = r = k;
  if(n < k) l = n;
  if(m < k) r = m;
  cout<<l*r<<endl;
}

int main() {
  int t=1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
