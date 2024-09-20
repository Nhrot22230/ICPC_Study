#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

const ll N = 1000000;
ll arrPrimos[N+1];

void criba(ll n){
    for(ll i=2; i<=n; i++) arrPrimos[i] = i;

    for(ll i=2; i*i<=n; i++){
        if(arrPrimos[i] != i) continue;
        for(ll j=i*i;j<=n; j+=i){
            if(arrPrimos[j] == j)
                arrPrimos[j] = i;
        }
    }
}

vector<pair<ll, ll>> factorizar(ll n){
    vector<pair<ll, ll>> factores;
    while(n>1){
        ll exponent = 0;
        ll p = arrPrimos[n];
        while(n%p==0){
            n/=p;
            exponent++;
        }
        pair <ll, ll> factor = make_pair(p, exponent);
        factores.push_back(factor);
    }
    return factores;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); criba(N);
    int testcases; 
    cin >> testcases;
    ll num;
    while(testcases--){    
        cin >> num;
        vector<pair<ll, ll>> factores = factorizar(num);
        ll divisors = 1;
        for(int i=0; i<(int)factores.size(); i++){
            divisors*=(factores[i].second+1);
        }
        cout << divisors << endl;
    }
    return 0;
}