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
  int t = 1;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    std::vector<int> v(n);
    for(int i=0; i<n; i++){
      cin>>v[i];
    }
    map<int,int> freq;
    map<int,int>::iterator it;
    int cant = 0;
    for(int i=n-1; i>=0; i--){
      it = freq.find(v[i]);
      if(it != freq.end()){
        if(it->second == 1){
          break;
        }else{
          it->second++;
        }
      }else{
        freq[v[i]] = 1;
      }
      cant ++;
    }
    cout<<n-cant<<endl;
  }
  return 0;
}
