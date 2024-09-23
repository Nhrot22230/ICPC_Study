#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<ll> primes;

void criba(){
    ll nsqrt = 1000000;
    vector<char> is_prime(nsqrt + 2, true);
    for (ll i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }
}

int main(){

    ll num;
    cin >> num;
    criba();
    int cant=0;

    if(num<2){
        cout << 0 << endl;
        return 0;
    }
    for (ll i = 0; i < primes.size(); i++)
    {   
        if(num%primes[i]==0){
            int temp = primes[i];
            int j=0;
            for(j = 0; num%temp==0; j++){
                num = num/temp;
                temp= temp*primes[i];
            }
            cant+=j;
        }
    }
    if(num>100000) cant++;
    cout << cant << endl;
    return 0;
}