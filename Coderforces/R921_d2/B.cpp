#include <bits/stdc++.h>

#define ll long long
#define ENDL '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

void Solve(void){
    ll x, n;
    cin >> x >> n;

    ll ans = 1;

    for(ll i=1; i<=x; i++){
        if(x%i == 0 && x/i >= n) ans = i;
        if(x/i < n) break;
    }
    
    cout << ans << endl;
}

int main(void){
    fastio;
    
    int t = 1;

    cin >> t;
    
    while (t--)
    {
        /* code */
        Solve();
    }
    

    return 0;
}