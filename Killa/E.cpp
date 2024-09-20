#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

void solve(){
    ull n;

    cin>>n;
    
    if(n%2 == 1){
        cout << -1 << endl;
        return;
    }

    ull a = (n >> 1);
    ull cont;
    for(ull i=0; i<= 60; i++){
        if( (n >> i) & 1ULL ) cont = i;
    }

    ull b = (1ULL << cont) - a;

    cout << a << " " << b << endl;
}

int main(){
    int t = 1;
    cin>>t;

    while(t--) solve();
    
    return 0;
}