#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

const ll N = 100000;
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

/*
    3
    2 3 4 5
    1 1 2 1
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(0); 
    criba(N);
    ll n;
    cin >> n;
    
    if(n>2) cout << 2 << endl;
    else cout << 1 << endl;
    
    for(ll i=2; i<=n+1;i++){
        if(arrPrimos[i] == i){
            cout << 1;
        }
        else{
            cout << 2;
        }
        cout << " ";
    }
    cout << endl;
    return 0;
}