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

int main(){
    criba(N);
    int testcases;
    cin >> testcases;
    ll num;
    while(testcases--){
        cin >> num;
        if(sqrt(num) - (ll) sqrt(num) < 0.0000001 ) {
            num = sqrt(num); 
            if(arrPrimos[num] == num) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}