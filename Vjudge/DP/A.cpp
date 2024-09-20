#include <bits/stdc++.h>

#define ENDL '\n'
#define ll long long
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);

using namespace std;


const int MAX_N = 4000 + 7;
int a, b, c;

ll dp[MAX_N] {};

ll DP(int i){
    if(i == 0) return 0;

    if(dp[i] != -1e5) return dp[i];

    if(i - a >= 0) dp[i] = max(dp[i], 1 + DP(i - a));
    if(i - b >= 0) dp[i] = max(dp[i], 1 + DP(i - b));
    if(i - c >= 0) dp[i] = max(dp[i], 1 + DP(i - c));

    return dp[i];
}

void Solve(void)
{
    int n;
    cin >> n >> a >> b >> c;

    for(int i=0; i<MAX_N; ++i) dp[i] = -1e5;

    cout << DP(n) << ENDL;
}

int main(void)
{
    fastio;
    
    size_t t = 1;

    //cin >> t;

    while (t--)
    {
        Solve();
    }
    
    return 0;
}