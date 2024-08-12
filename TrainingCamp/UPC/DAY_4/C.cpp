#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  set<char> s;

  while ( cin >> c ) {
    if(c == '{' || c == '}' || c == ',') continue;
    s.insert(c);
  }

  cout << s.size() << endl;
  return 0;
}
