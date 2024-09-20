#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

int main(){
    ll maxNum; int k;
    cin >> maxNum >> k;
    ll arrPrimos[k];
    for(int i=0; i<k; i++) 
        cin >> arrPrimos[i];

    ll prod, suma=0;
    for(ll i=1; i < 1<<k; i++){

        prod=1;

        int contBits=0;
        for(int j=0; j<k; j++){
            if(i>>j&1){
                if (prod >= maxNum/arrPrimos[j] + 1) {
                    prod = maxNum + 1;
                    break;
                }
                prod *= arrPrimos[j];
                contBits++;
            }
        }
        ll resultado = maxNum/prod;
        if(contBits&1) 
            suma += resultado;
        else
            suma -= resultado;
    }
    cout << suma << endl;
    return 0;
}