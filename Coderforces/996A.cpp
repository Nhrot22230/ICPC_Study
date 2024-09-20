#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
  vector<ll> bills = {100, 20, 10, 5, 1};
  ll n; cin >> n;

  ll cont = 0;
  for(int bill : bills) {
    int k = (n / bill);
    n = n - k*bill;
    cont += k;
  }
  cout << cont << endl;
}

int main(){
  int t=1;
  //cin >> t;
  while(t--) solve();

  return 0;
}
