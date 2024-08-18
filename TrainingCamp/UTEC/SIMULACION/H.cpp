#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve(){
  ll n;
  cin>>n;
  ll copia=n;
  vector<ll> color(n);
  for(ll i=0;i<n;i++) cin>>color[i];
  sort(color.begin(),color.end(),greater<ll>());

  int exp=0;
  while(copia>1){
    exp++;
    copia/=4;
  }
  exp++;
  ll sum=0;
  while(exp--){
    for(ll i=0;i<n;i++) sum+=color[i];
    n/=4;
  }
  cout<<sum;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t=1;
  //cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
