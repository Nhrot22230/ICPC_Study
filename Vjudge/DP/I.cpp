#include <bits/stdc++.h>

#define ENDL '\n'
#define ll long long
#define ull unsigned long long
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);

using namespace std;


const int MAX_N = 1e5 + 7;

ull dp[MAX_N] {};
/*

S : S(i) Maxima suma hasta i sin repetir eleccion +2 veces seguidas;
R : Si ayer eleji X hoy no puedo 
T : 

B : 
O : 
T : 

*/

ll cont = 0; // Lo uso para saber cuantas veces se llama la func tehehe

ull DP(ull i){
    cont++;
    if(i==0) return 0;

    return dp[i];
}

void Solve(void)
{
    ull w;
    cout << DP(w) << ENDL;
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