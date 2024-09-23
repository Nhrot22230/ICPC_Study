#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
  int n; cin >> n;
  int p; cin >> p;
  set<int> lvls;
  while(p--) {
    int num; cin >> num;
    lvls.insert(num);
  }
  int q; cin >> q;
  while(q--){
    int num; cin >> num;
    lvls.insert(num);
  }

  if(lvls.size() == n) {
    cout << "I become the guy." << endl;
  }
  else{
    cout << "Oh, my keyboard!" << endl;
  }
}

int main(){
  int t=1;
  //cin >> t;
  while(t--) solve();

  return 0;
}
