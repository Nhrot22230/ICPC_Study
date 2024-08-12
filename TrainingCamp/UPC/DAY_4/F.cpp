#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int INF = 2*1e8;

void solve(){typedef long long Long;
typedef pair<int, int> Pair;

  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin>>v[i];
  }

  int min = INF, ind_min;
  for(int i=0; i<n; i++){
    if(v[i] <= min){
      ind_min = i;
      min = v[i];
    }
  }
  int ans = 0;
  for(int i = ind_min; i<n-1; i++){
    swap(v[i], v[i+1]);
    ans ++;
  }
  int max = -INF, ind_max;
  for(int i=0; i<n; i++){
    if(v[i] > max){
      ind_max = i;
      max = v[i];
    }
  }
  for(int i=ind_max; i>0; i--){
    swap(v[i], v[i-1]);
    ans ++;
  }
  cout<<ans<<endl;
}


int main(){
  fastio;
  int t = 1;
  while(t--) solve();
  return 0;
}
