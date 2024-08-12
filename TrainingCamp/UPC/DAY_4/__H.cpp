#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  string s; cin >> s;
  vector<ll> hash_arr(s.length() + 1);

  const int p = 31;
  const int m = 1e9 + 9;
  ll hash_value = 0;
  ll p_pow = 1;

  for(int i=0; i<s.length(); i++) {
    hash_arr[i] = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
    hash_value = hash_arr[i];
  }

  p_pow = p;
  for(int i = 1; i<s.length(); i++) {

  }

  return 0;
}
