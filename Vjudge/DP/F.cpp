#include <bits/stdc++.h>

#define ENDL '\n'
#define ll unsigned long long
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);

using namespace std;


const int MAX_N = 1e5 + 7;

bool done[MAX_N] {};
ll dp[MAX_N] {};
ll nums[MAX_N] {};


ll cont = 0; // Lo uso para saber cuantas veces se llama la func tehehe
ll DP(ll i){
    cont++;
    if(i == 0) return 0;
    if(i == 1) return nums[1];

    if(done[i]) return dp[i];

    dp[i] = max(nums[i]*i + DP(i-2), DP(i-1));

    done[i] = true;
    
    return dp[i];
}

void Solve(void)
{
    ll n;
    cin >> n;

    ll max_value = 0;
    for(size_t i =0; i<n; ++i){
        ll num;
        cin >> num;

        max_value = max(max_value, num);

        nums[num] ++;
    }
    
    cout << DP(max_value) << ENDL;
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