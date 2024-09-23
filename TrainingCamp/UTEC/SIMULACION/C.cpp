#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve() {
  int n, src_x, src_y, dest_x, dest_y;
  cin >> n >> src_x >> src_y >> dest_x >> dest_y;

  string s; cin >> s;

  int i=0;
  for(i=0; i<n; i++) {
    if (src_x == dest_x && src_y == dest_y) {
      cout << i << endl;
      return;
    }

    if(s[i] == 'S' && dest_y < src_y) src_y--;
    if(s[i] == 'E' && dest_x > src_x) src_x++;
    if(s[i] == 'W' && dest_x < src_x) src_x--;
    if(s[i] == 'N' && dest_y > src_y) src_y++;
  }

  if (src_x == dest_x && src_y == dest_y) {
    cout << n << endl;
    return;
  }
  cout << -1 << endl;
}

int main() {
  int t=1;
  //cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
