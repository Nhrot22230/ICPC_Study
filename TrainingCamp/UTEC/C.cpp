#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;

typedef struct {
  double x;
  double y;
} Punto;

typedef struct {
  double dy;
  double dx;
  double c;
} Recta;

double distPP(Punto p1, Punto p2) {
  return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

double distPR(Punto p, Recta r) {
  double numerador = fabs(r.dx * p.x + r.dy * p.y + r.c);
  double denominador = sqrt(r.dx * r.dx + r.dy * r.dy);
  return numerador / denominador;
}

Recta crearRecta(Punto p1, Punto p2) {
  Recta r;
  r.dy = p2.y - p1.y;
  r.dx = p1.x - p2.x;
  r.c = p2.x * p1.y - p1.x * p2.y;

  return r;
}


void solve() {
  int n; cin >> n;
  vector<Punto> arr;
  while(n--) {
    double x, y; cin >> x >> y;
    arr.push_back({x, y});
  }
  double x, y;
  cin >> x >> y;
  Punto from = {x, y};
  cin >> x >> y;
  Punto to = {x, y};
  Recta r = crearRecta(from, to);

  for(Punto c : arr) {

  }
}

int main() {
  int t=1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
