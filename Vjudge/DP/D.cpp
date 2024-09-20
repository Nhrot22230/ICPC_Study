#include <bits/stdc++.h>

#define ENDL '\n'
#define ll unsigned long long
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);

using namespace std;


const int MAX_N = 1e5 + 7;

ll dp[MAX_N] {};

/*
    3120101
S : S(i)
R : En caso de 0Y | XY > 26 -> solo hay una forma
T : 

B : 
O : 
T : 

*/
ll cont = 0; // Lo uso para saber cuantas veces se llama la func tehehe

ll DP(string &s, int i){
    cont++;
    if(i <= 1) return 1;

    if(dp[i]) return dp[i];

    if( (s[i-2] == '0') | 
    (s[i-2] == '2' & s[i-1] >= '7') | 
    (s[i-2] >= '3')) dp[i] = DP(s, i-1);
    else if(s[i-1] == '0') dp[i] = DP(s, i-2);
    else dp[i] = DP(s, i-1) + DP(s, i-2);

    return dp[i];
}

bool Solve(void)
{
    string s;
    cin >> s;

    if(s == "0") return false;

    int n = s.length();

    cout << DP(s, n) << ENDL;
    for(size_t i=0; i<=n; ++i) dp[i]=0;

    return s.length();
}

int main(void)
{
    fastio;

    while (Solve());
    
    return 0;
}