#include <bits/stdc++.h>

#define ENDL '\n'
#define ll unsigned long long
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);

using namespace std;


const int MAX_N = 2e5 + 7;

bool done[MAX_N] {};
ll dp[MAX_N] {};

ll dp_manco[MAX_N] {};
ll dp_yo[MAX_N] {};

vector<int> boss;

ll cont = 0; // Lo uso para saber cuantas veces se llama la func tehehe
//ll DP(bool myTurn, ll i){
ll DP(int i){
    cont++;
    

    // Decisiones: 
    // - En cada turno (
    //      matar 1 o 2 jefes)
    // - Si es turno de mi amigo y se encuentra con un boss hard (
    //      si mato a uno ya que m pase el mando si no usar skill point)

    // Objetivo:
    // - Minimizar el uso de skip points x el manco de mi pata

    // ?:
    // - Deberia hacer un dp de mi pata y otro mio como en la C? --Nah --Correcion: Si creo xd
    // - Deberia hacerlo iterativo en todo caso xd? --Puede ser --Mmmm
    
    // if(myTurn) dp[i] = min(DP(false, i+1), DP(false, i+2));
    // else dp[i] = boss[i] + min(DP(true, i+1), boss[i+1] + DP(true, i+2));
    // if(i >= (int) boss.size() ) return 0;
    // if(done[i]) return dp[i];
    if(i == 0) return 0;
    DP(i - 1);
    if(i == 1){
        dp_manco[i] = boss[i] + dp_manco[i-1];
        dp_yo[i] = dp_manco[i-1];
    }
    else{
        dp_manco[i] = boss[i] + min(dp_yo[i-1], boss[i-1] + dp_yo[i-2]);
        dp_yo[i] = min(dp[i-1], dp[i-2]);
    }

    dp[i] = dp_manco[i];
    
    //cout << i << "=" << dp[i] << endl;
    return dp[i];
}

void Solve(void)
{
    ll n;
    cin >> n;
    boss.clear();
    boss.resize(n+1);

    for(size_t i = 0; i<n; ++i) cin >> boss[i];

    // Creo que este problema se hara mas facil si lo hago iterativo jeje
    // Post Comentario: no lo fue xD

    //cout << DP(false, 1) << endl;
    //for(size_t i=0; i<=n; ++i) done[i] = false;
    
    dp[0] = dp_yo[0] = dp_manco[0] = boss[0];
    //cout << "-------------------------------------------" << endl;
    cout << DP(n) << endl;
    //cout << cont << ENDL;
}

int main(void)
{
    fastio;
    
    size_t t = 1;

    cin >> t;

    while (t--)
    {
        Solve();
    }
    
    return 0;
}