#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int num=0;
    int i=0, j=0;
    for(i=0; i<25; i++){
        cin >> num;
        if(num) break;
    }
    j = i%5; i = i/5;
    cout << abs(i-2) + abs(j-2) << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}