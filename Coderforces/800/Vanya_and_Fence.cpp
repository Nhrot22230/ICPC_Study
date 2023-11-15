#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int n, h;
    cin >> n >> h;
    int doblados_xd = 0;
    int a;
    for(int i=0; i<n; i++){
        cin >> a;
        if(a>h) doblados_xd++;
    }
    cout << doblados_xd + n << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}