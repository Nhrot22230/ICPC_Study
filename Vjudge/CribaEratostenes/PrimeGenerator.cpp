#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

using namespace std;

vector<char> segmentedSieve(ll L, ll R) {
    ll lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<ll> primes;
    for (ll i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (ll j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

int main(){
    ll t, a, b;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld", &a, &b);
        vector<char> primes = segmentedSieve(a, b);
        for(ll i=0; i<(ll)primes.size(); i++){
            if(primes[i]) printf("%lld\n", i+a);
        }
    }
    return 0;
}

