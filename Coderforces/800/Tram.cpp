#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int curCapacity = 0, maxCapacity = 0;
    int n, a, b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        curCapacity += b - a;
        maxCapacity = max(maxCapacity, curCapacity);
    }
    cout << maxCapacity << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}