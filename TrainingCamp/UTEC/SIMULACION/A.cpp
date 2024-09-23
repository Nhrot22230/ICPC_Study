#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve() {
  int n, mesaD1, mesaD2;
  cin >> n >> mesaD1 >> mesaD2;
  int mesa2L1 = 0, mesa2L2 = mesaD2;

  int cont = 0;
  for (int i = 0; i < n; i++) {
    int income = 0;
    cin >> income;
    if (income == 1) {
      if (mesaD1 > 0) mesaD1--;
      else if (mesa2L2 > 0) { mesa2L2--; mesa2L1++; }
      else if (mesa2L1 > 0) mesa2L1--;
      else cont += income;
    } else if (income == 2) {
      if (mesa2L2 > 0) mesa2L2--;
      else cont += income;
    }
  }
  cout << cont << endl;
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
      solve();
    }
    return 0;
}
