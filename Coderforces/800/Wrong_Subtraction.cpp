#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    while(k--){
        n = n%10 ? n-1 : n/10;
    }
    cout << n << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}