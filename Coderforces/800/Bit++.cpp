#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int num = 0;
    int n;
    cin >> n;

    char c1,c2,c3;
    while(n--){
        cin >> c1 >> c2 >> c3;
        if(c2 == '+') num++;
        else num--;
    }
    cout << num << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}