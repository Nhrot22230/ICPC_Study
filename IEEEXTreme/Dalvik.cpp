#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mi_abs(ll num){
    if(num <= 0){
        num = -num;
    }
    return num;
}

ll solve(ll v0,ll v1,ll v2){
    ll v6 = 1;
    ll v9=v0+v1;
    ll v12=1;
    ll v13;
    do{
        v13 = v0*v12; 
        v13 = v13 - (ceil( ((double)v13)/v1-0.5 )*v1 ); 
        
        if(v13 <= 0) v13 = -v13;
        
        if( v13*(v6+1) < v9*(v12+1) ){ 
            v6=v12; 
            v9=v13; 
        }
        v12++; 
    }while(v12<=v2);

    return v6;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t= 1;
    cin >> t;
    while(t--){
        ll v0, v1, v2;
        cin >> v0 >> v1 >> v2;
        cout << solve(v0, v1, v2) << '\n';
    }
    return 0;
}
