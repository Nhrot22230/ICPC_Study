#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    int num;
    while (n--){
        cin >> num;
        if(num){
            cout << "HARD" << endl;
            return;
        }
    }
    cout << "EASY" << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}