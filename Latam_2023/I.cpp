#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ll freq[30] = {};
    ll INV_PRO = 0, INV_SIG = 0;
    string s;
    cin >> s;
    ll n;
    cin >> n;

    for (char c : s) {
        int idx = c - 'a';
        freq[idx]++;
        for (int i = idx + 1; i < 30; i++) {
            INV_PRO = (INV_PRO + freq[i]) % MOD;
        }
    }

   	ll sum = 0;
	for (int i=0; i < 30; i++) {
	    INV_SIG = (INV_SIG + (freq[i] * sum)%MOD)%MOD;
		sum = (sum + freq[i])%MOD;
	}

    ll temp = 0;
    ll a = n % MOD;
    ll b = (n - 1) % MOD;
    temp = (INV_SIG * a) % MOD;
    temp = (temp * b) % MOD;

    ll inv2 = (MOD + 1) / 2; // Esto es válido si MOD es impar
    temp = (temp * inv2) % MOD;

    ll ans = ((INV_PRO * a) % MOD + temp) % MOD;
    cout << ans << endl;
    return 0;
}
