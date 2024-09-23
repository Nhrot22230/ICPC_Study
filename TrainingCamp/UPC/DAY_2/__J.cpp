#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[100];

ll DP(ll i, int *arr) {
  cout << i << endl;
  if(dp[i] != -1) return dp[i];
  if (i == 1) {
    dp[i] = (arr[i - 1] + arr[i])%100;
    return arr[i - 1] * arr[i];
  }

  if (i == 0) {
    return 10000000000;
  }

  int a = (DP(i-1, arr) + arr[i]) % 100;
  int b = (arr[i - 1] + arr[i]) % 100 * DP(i-1, arr);

  dp[i] = min(a,b);
  return dp[i];
}



void solve(int n) {
  int arr[n];
  for(int i=0; i<n; i++) cin >> arr[i];

  for(int i=0; i<n; i++) dp[i] = -1;
  cout << DP(n - 1, arr) << endl;

  for(int i=0; i<n; i++) cout << dp[i] << " ";
  cout << endl;
}

int main() {
  int n;
  while (cin >> n) {
    solve(n);
  }
  return 0;
}
