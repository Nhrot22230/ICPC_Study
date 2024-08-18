#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void aux(int &Person, int &grape) {
  if(Person > grape) {
    Person = Person - grape;
    grape = 0;
  }
  else {
    grape = grape - Person;
    Person = 0;
  }
}

void solve() {
  int Andrew, Dmitry, Michael; cin >> Andrew >> Dmitry >> Michael;
  int g, p, b; cin >> g >> p >> b;

  if(Andrew > g) {
    cout << "NO" << endl;
    return;
  }
  g = g - Andrew;
  Andrew = 0;
  aux(Dmitry, g);
  aux(Dmitry, p);

  if(Michael <= g + p + b) Michael = 0;
  if(Andrew == 0 && Dmitry == 0 && Michael == 0) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  int t=1;
  //cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
