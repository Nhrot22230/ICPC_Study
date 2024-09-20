#include <bits/stdc++.h>
using namespace std;

void usaco(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}

typedef long long Long;
typedef unsigned long long ull;
typedef pair<int, int> Pair;
const int INF = 1e9 + 1;
const int N = 1000000;
const int MOD = 1e9 + 7;

void solve() {
  while(true){
    vector<int> a(4);
    vector<int> b(4);
    vector<int> ans(4,0);

    int cant = 0;
    for(int i=0; i<4; i++){
      cin>>a[i];
      cant +=  a[i];
    }
    for(int i=0; i<4; i++) cin>>b[i];

    if(a[0] == -1) break;
    if(cant == 0){
      for(int i=0; i<4; i++){
        cout<<0<<" ";
      }
      cout<<endl;
      continue;
    }
    for(int i=0; i<4; i++){
      if(a[i]%b[i] == 0) continue;
      ans[i] = b[i]-(a[i]%b[i]);
      a[i] += ans[i];
    }
    int max_div = -1;
    vector<int> divi(4);
    for(int i=0; i<4; i++){
      divi[i] = a[i]/b[i];
      max_div = max(max_div, divi[i]);
    }

    for(int i=0; i<4; i++) cout<<(max_div*b[i]-a[i])+ans[i]<<" ";
    cout<<endl;
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
