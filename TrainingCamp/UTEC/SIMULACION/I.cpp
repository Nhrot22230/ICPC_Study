#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve(){
  int n; cin >> n;
  if(n%2 == 0) {
    cout << "white" << endl;
    cout << "1 2" << endl;
  }
  else {
    cout << "black" << endl;
  }
}

int main(){
  int t=1;
  //cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
