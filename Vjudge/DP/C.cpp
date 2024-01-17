#include <bits/stdc++.h>

#define ENDL '\n'
#define ll long long
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);

using namespace std;


const int MAX_N = 1e5 + 7;

ll dp[MAX_N] {};

ll dp_a[MAX_N] {};
ll dp_b[MAX_N] {};
ll dp_c[MAX_N] {};


ll a[MAX_N] {};
ll b[MAX_N] {};
ll c[MAX_N] {};


/*

S : S(i) Maxima suma hasta i sin repetir eleccion +2 veces seguidas;
R : Si ayer eleji X hoy no puedo 
T : 

B : 
O : 
T : 

*/
ll cont = 0; // Lo uso para saber cuantas veces se llama la func tehehe

ll DP(int i){
    cont++;
    if(i == 0) return 0;
    DP(i-1);

    dp_a[i] = a[i] + max(dp_b[i-1], dp_c[i-1]) ;
    dp_b[i] = b[i] + max(dp_c[i-1], dp_a[i-1]) ;
    dp_c[i] = c[i] + max(dp_a[i-1], dp_b[i-1]) ;

    dp[i] = max(dp_a[i], max(dp_b[i], dp_c[i]));

    return dp[i];
}

void Solve(void)
{
    int n;
    cin >> n;

    for(size_t i=0; i<n; ++i) cin >> a[i] >> b[i] >> c[i];

    dp_a[0] = a[0]; dp_b[0] = b[0]; dp_c[0] = c[0];

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