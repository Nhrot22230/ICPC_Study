#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  vector<ll> cards(n);
  ll sum=0;
  for(int i=0; i<n; i++) {
    cin >> cards[i];
    sum += cards[i];
  }

  sum = abs(sum);
  ll cont = 0;
  for(int i = abs(x); i > 0; i--) {
    ll k = (sum / i);
    if(sum - k*i >= 0) {
      sum -= k*i;
      cont += k;
    }
  }

  cout << cont << endl;
}

int main() {
  int t=1;
  //cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
