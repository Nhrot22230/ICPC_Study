#include <algorithm>
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void solve() {
  ll n; cin >> n;
  vector<pair<ll,ll>> cards(n);
  for(ll i=0; i<n; i++) {
    cin >> cards[i].first >> cards[i].second;
    if(cards[i].first == cards[i].second) cards[i].second = 0;
  }

  vector<ll> aux(n);
  for(ll i=0; i<n; i++) aux[i] = cards[i].first;
  sort(aux.begin(), aux.end());

  ll ga = 0;
  ll freq = 0;
  for(ll i=0; i<n; i++) {
    if(freq*2 >= n) {
      cout << 0 << endl;
      return;
    }
    if(ga != aux[i]) { freq=0; ga = aux[i]; }
    freq++;
  }
  if(freq*2 >= n) {
    cout << 0 << endl;
    return;
  }

  aux = vector<ll>(2*n);
  for(ll i=0; i<n; i++) aux[i] = cards[i].first;
  for(ll i=0; i<n; i++) aux[n + i] = cards[i].second;
  sort(aux.begin(), aux.end());
  ga = 0;
  freq = 0;
  bool flag = false;
  set<ll> candidates;
  for(ll i=0; i<aux.size(); i++) {
    if(freq*2 >= n && ga != 0) {
      flag = true;
      candidates.insert(ga);
    }
    if(ga != aux[i]) { freq=0; ga = aux[i]; }
    freq++;
  }
  if(freq*2 >= n && ga != 0) {
    candidates.insert(ga);
    flag = true;
  }
  if(flag == false) {
    cout << -1 << endl;
    return;
  }

  ll maxCards = 0;
  for(ll cand : candidates) {
    ll cont=0;
    for(ll i=0; i<n; i++) {
      cont+=(cand == cards[i].first);
    }
    maxCards = max(maxCards, cont);
  }

  cout << (n + 1)/2 - maxCards << endl;
}

int main() {
  ll t=1;
  //cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
