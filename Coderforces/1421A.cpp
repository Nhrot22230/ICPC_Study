#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
  int a, b;
  cin >> a >> b;

  cout << (a | b) - (a & b) << endl;
}

int main(){
  int t=1;
  cin >> t;
  while(t--) solve();

  return 0;
}
