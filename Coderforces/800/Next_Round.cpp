#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int num  = 0;
    int comp = 0;
    int i=0;

    for(; i<n; i++){
        cin >> num;
        if(num == 0){break;}
        if(i == k-1) comp = num;
        if(comp && num<comp) break;
    }
    cout << i << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}