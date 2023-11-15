#include <bits/stdc++.h>
#define ll long long
#define endl '\n'


using namespace std;

const int MOD = 998244353;
ll dp[10000000]{1};

ll combinatoria(ll num, ll base){
    if(dp[base%10000000]) return dp[base];

    return dp[base%10000000] = ( ((num - base + 1)*combinatoria(num, base - 1))%MOD/(base%MOD) )%MOD;
}

int main(){
    int k, n;
    cin >> k >> n;
    combinatoria(n, n);

    // for(int i=0; dp[i]; i++){
    //     cout << dp[i] << "  ";
    // }
    // cout << endl;

    for(int j=0; j< 1<<k ; j++){
        ll suma = 0;
        for(int i=j; i<=n; i+= 1<<k){
            suma = (suma%MOD + dp[i]%MOD)%MOD;
        }
        cout << suma << " ";
    }
    cout << endl;
    return 0;
}
