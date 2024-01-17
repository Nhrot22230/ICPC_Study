#include <bits/stdc++.h>

#define ENDL '\n'
#define ll long long
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);

using namespace std;


const int MAX_N = 1e5 + 7;

ll dp[MAX_N] {};

ll W[MAX_N] {};
ll V[MAX_N] {};

ll cont = 0; // Lo uso para saber cuantas veces se llama la func tehehe

ll DP(ll i){
    cont++;

    if(dp[i]) return dp[i];



    return dp[i];
}

void Solve(void)
{
    ll n, w;
    cin >> n >> w;

    for(size_t i =0; i<n; ++i) cin >> W[i] >> V[i];

    cout << DP(n) << ENDL;
    //cout << cont << ENDL;
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