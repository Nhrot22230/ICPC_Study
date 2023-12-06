#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define ft first
#define sc second

using namespace std;

int n;
vector<int> a;

inline void read() {
  cin >> n;
  a.clear();
  for (int i = 0; i < 2 * n; i++) {
      int x;
      cin >> x;
      a.pb(x);
  }
}
inline void solve() {
    sort(all(a));
    vector<pair<int, int> > pts;
    for (int i = 0; i < n; i++) {
        pts.pb(mp(a[i], a[i + n]));
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += abs(pts[i].ft - pts[i - 1].ft) + abs(pts[i].sc - pts[i - 1].sc);
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << pts[i].ft << ' ' << pts[i].sc << endl;
    }
}
 
int main () {
    int t;
    cin >> t;
    while (t--){
        read();
        solve();
    }
}