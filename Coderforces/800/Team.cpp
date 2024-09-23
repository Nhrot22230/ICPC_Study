#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int n, Petya, Vasya, Tonya;
    cin >> n;
    int ans = 0;
    while(n--){
        cin >> Petya >> Vasya >> Tonya;
        ans += (Petya + Vasya + Tonya)>1;
    }
    cout << ans << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}