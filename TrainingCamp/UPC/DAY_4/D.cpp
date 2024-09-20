#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef struct {
  int x;
  int y;
} Coord;

void solve(int n) {
  vector<Coord> points(n);
  set<pair<int,int>> pends;
  int i=0;

  int ga = n;
  while(ga--) {
    int x, y;
    cin >> x >> y;
    points[i] = {x, y};
    i++;
  }

  for(i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
      Coord p1 = points[i];
      Coord p2 = points[j];
      int difX = p1.x - p2.x;
      int difY = p1.y - p2.y;
      int temp = __gcd(abs(difX), abs(difY));

      if (difY*difX == 0) {
        difY = (difX == 0);
        difX = (difY == 0);
        pends.insert({difY, difX});
        continue;
      }
      else if (difX < 0 && difY < 0) {
        difX = abs(difX);
        difY = abs(difY);
      }
      else if (difX < 0 && difY > 0) {
        difX = abs(difX);
        difY = abs(difY)*-1;
      }
      pends.insert({difY/temp, difX/temp});
    }
  }

  //for(auto p : pends) cout << p.first << "/" << p.second << endl;

  cout << pends.size() << endl;
}

int main() {
  int n;
  while (cin >> n && n != 0) solve(n);
  return 0;
}
