#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

const ll N = 1000;
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

ll getNextPrime(ll n){
    for(ll i=n+1; i<N; i++){
        if(arrPrimos[i]==i) return arrPrimos[i];
    }
    return 0;
}

ll getPreviousPrime(ll n){
    for(ll i=n; i>2; i--){
        if(arrPrimos[i]==i) return arrPrimos[i];
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    if(n < 11 && k > 0){
        cout << "NO" << endl;
        return 0;
    }
    criba(N);
    int cont=0;
    for(int i=13; i<=n; i++){
        if(arrPrimos[i] != i) continue;
        if(arrPrimos[i] == (getPreviousPrime(i/2) + getNextPrime(i/2) + 1)) {
            cont++;
            //cout << arrPrimos[i] << "=" << getPreviousPrime(i/2) <<"+" << getNextPrime(i/2) << "+1" << endl;
            continue;
        }
    }
    if(cont >= k) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}