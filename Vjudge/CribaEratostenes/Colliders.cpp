#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

const ll N = 100000;
ll arrPrimos[N+1];

void criba(ll n){
    for(ll i=0; i<=n; i++) arrPrimos[i] = i;

    for(ll i=2; i*i<=n; i++){
        if(arrPrimos[i] != i) continue;
        for(ll j=i*i;j<=n; j+=i){
            if(arrPrimos[j] == j)
                arrPrimos[j] = i;
        }
    }
}

void activarCollider(ll arrCollider[], ll n){
    ll numCopy=n;
    if(arrCollider[n] == n){
        cout << "Already on" << endl;
        return;
    }
    while(n>1){
        if(arrCollider[arrPrimos[n]]){
            cout << "Conflict with " << arrCollider[arrPrimos[n]] << endl;
            return;
        }
        n=n/arrPrimos[n];
    }   
    n = numCopy;
    
    arrCollider[n] = numCopy;
    
    while(n>1){
        arrCollider[arrPrimos[n]] = numCopy;
        n=n/arrPrimos[n];
    }
    cout << "Success" << endl;
}

void desactivarCollider(ll arrCollider[], ll n){
    if(arrCollider[n] == n){
        arrCollider[n] = 0;
        while(n>1){
            arrCollider[arrPrimos[n]] = 0;
            n=n/arrPrimos[n];
        }
        cout << "Success" << endl;
    }
    else
        cout << "Already off" << endl;
}

int main(){
    ll n, m, i;
    char symbol;
    cin >> n >> m;
    criba(N);
    ll arrCollider[n+1]{};
    while(m--){
        cin >> symbol >> i;
        if(symbol == '+'){
            activarCollider(arrCollider, i);
        }
        else{
            desactivarCollider(arrCollider, i);
        }
        // for(int j=1; j<=n; j++){
        //     cout << arrCollider[j] << "  ";
        // }
        // cout << endl;
    }
    return 0;
}
