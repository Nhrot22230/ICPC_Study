#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i=5; i>0; i--){
        ans += n/i;
        n = n%i;
    }

    cout << ans << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}