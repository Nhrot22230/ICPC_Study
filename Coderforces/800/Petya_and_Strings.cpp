#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    char letra;
    string s1;
    cin >> s1;
    for(int i=0; i<s1.size(); i++){
        cin >> letra;
        if(tolower(letra) > tolower(s1[i])) {
            cout << -1 << endl;
            return;
        }
        if(tolower(letra) < tolower(s1[i])) {
            cout << 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}