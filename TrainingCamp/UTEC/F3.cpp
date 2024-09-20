#include <bits/stdc++.h>
#define ENDL '\n'
#define ll long long
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);

using namespace std;
const int N = 100 + 5;
const int INF = 0x3f3f3f3f;

vector<ll> wt(N);
vector<ll> val(N);
vector<vector<ll>> dp(N, vector<ll> (1e5 + 7));

// Returns the value of maximum profit
ll knapSackRec(int W, int index)
{
  if (index < 0) return 0;
  if (dp[index][W] != -1) return dp[index][W];

  if (wt[index] > W) {
    dp[index][W] = knapSackRec(W, index - 1);
    return dp[index][W];
  }
  dp[index][W] = max(val[index] + knapSackRec(W - wt[index], index - 1), knapSackRec(W, index - 1));
  return dp[index][W];
}

int main() {
  int n, W, V = 0;
  cin >> n >> W;

  for (int i = 1; i <= n; ++i) {
    cin >> wt[i] >> val[i];
    V += val[i];
  }
  for(int i = 0; i<N; i++) {
    dp[i].assign(dp[i].size(), -1);
  }
  cout << knapSackRec(W, n) << endl;
}
