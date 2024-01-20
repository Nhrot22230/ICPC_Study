#include <bits/stdc++.h>

#define ENDL '\n'
#define ll long long
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);

using namespace std;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int w[maxn], v[maxn];
ll dp[maxn];

int main() {
    int n, W, V = 0;
    cin >> n >> W;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
        V += v[i];
    }

    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = V; j >= v[i]; --j) {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    for (int i = V; i >= 0; --i) {
        if (dp[i] <= W) {
            cout << i << endl;
            return 0;
        }
    }
}