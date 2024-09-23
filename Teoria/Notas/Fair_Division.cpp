#include <bits/stdc++.h>
#define ll unsigned long long
#define endl '\n'

using namespace std;

unsigned long long binpow(unsigned long long a, unsigned long long b) {
    unsigned long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ll n, t;
    cin >> n >> t;

    ll factor_up, factor_down, a, b; 
    bool encontrado = false;

    for(b=2; b<=100; b++){
        for(a=1; a<b; a++){
            factor_up = t * a * binpow(b, n-1);
            factor_down = binpow(b, n) - binpow(b-a, n);

            cout << factor_up << "\t%\t\t" << factor_down << endl;
            if(factor_up % factor_down == 0){
                encontrado = true;
                break;
            }
        }
        if(encontrado) break;
    }
    if(encontrado) cout << a << " " << b;
    else cout << "IMPOSSIBLE";
    cout << endl;
    return 0;
}
