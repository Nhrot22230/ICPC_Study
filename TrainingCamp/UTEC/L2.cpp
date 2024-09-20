#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve() {
	string s;
	cin >> s;

	int ans = 1;
	bool aux = false;
	for (int i = 0; i + 1 < s.length(); i++) {
		ans += (s[i] != s[i + 1]);
		aux = aux || (s[i] == '0' && s[i + 1] == '1');
	}
	cout << ans - aux << '\n';
}

int main() {
  int t=1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
