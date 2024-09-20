#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[107][107][107] = {};

ll DP(int i, int u_b, int u_n, vector<int> &v) {
  if (i == (int) v.size()) return 100000000;

  ll aux = 0;
  if (dp[i][u_b][u_n]) return dp[i][u_b][u_n];

  if (v[i] > v[u_b]) aux = DP(i + 1, i, u_n, v);
  if (v[i] < v[u_n]) aux = DP(i + 1, u_b, i, v);

  return dp[i][u_b][u_n] = min(DP(i + 1, u_b, u_n, v) + 1, aux);
}


int main() {
  int n;
  while (cin >> n && n != -1) {
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    cout << DP(0, 0, 0, nums) << endl;
  }

  return 0;
}
