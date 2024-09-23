#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

bool entraEnPresupuesto(ll target, ll n, ll k, vector<ll> &chefs, vector <ll> &platos){
    ll count = 0;
    for(int i=0; i<n; i++){                                                 // reducir a cada chef 
        ll demora = platos[i] * chefs[i] - target;                          // demora de cada chef reducido
        count += max(0LL,  (demora + platos[i] - 1)/platos[i] );            // que no sea menor 0 la reduccion
    }
    return count <= k;
}

int main(){
    ll n, k;
    cin >> n >> k;
    vector <ll> chefs(n);
    vector <ll> platos(n);
    
    for(int i=0; i<n; i++) cin >> chefs[i];
    for(int i=0; i<n; i++) cin >> platos[i];
    sort(chefs.begin(), chefs.end());
    reverse(chefs.begin(), chefs.end());
    sort(platos.begin(), platos.end()); 
    
    ll low = 0, high = 1e18;
    while (low < high)
    {
        ll mid = low + (high - low)/2;
        if(entraEnPresupuesto(mid, n, k, chefs, platos)) high = mid;
        else low = mid + 1;
    }
    
    cout << low << endl;
    return 0;
}