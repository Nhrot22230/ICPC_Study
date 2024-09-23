#include <bits/stdc++.h>
using namespace std;

void usaco(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

typedef long long Long;
typedef pair<int, int> Pair;
const int INF = 1e9 +1;
const int N = 100001;
const int MOD = 1e9 +7;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  usaco();
  int t = 1;
  while(t--){
    int n,k;
    cin>>n>>k;
    multiset<Pair> v;
    for(int i=0; i<n; i++){
      int e;
      cin>>e;
      v.insert({e, 0});
    }
    int piglet = 0;
    while(!v.empty()){
      auto it = prev(v.end());
      Pair jar = *it;
      v.erase(it);
      if(jar.first < k or jar.second == 3){
        piglet += jar.first;
      }else{
        jar.second ++;
        jar.first -= k;
        v.insert(jar);
      }
    }
    cout<<piglet<<endl;
  }
  return 0;
}
