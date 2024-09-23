#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    int poly_strength, poly_endurance;
    cin >> poly_strength >> poly_endurance;
    n--;

    int s, e;
    int gg = 0;
    while(n--){
        cin >> s >> e;
        if(s < poly_strength) continue;

        gg += (e >= poly_endurance);
    }
    if(gg) cout << -1 << endl;
    else cout << poly_strength << endl;
}

int main(){
    int t=1;
    cin >> t;
    while(t--) solve();

    return 0;
}