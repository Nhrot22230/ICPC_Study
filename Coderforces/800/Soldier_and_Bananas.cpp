#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int k, n, w;
    cin >> k >> n >> w;
    
    int sum = 0;
    for(int i=1; i<=w; i++) sum += i*k;

    if(n >= sum) cout << 0 << endl;
    else cout << sum - n << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}