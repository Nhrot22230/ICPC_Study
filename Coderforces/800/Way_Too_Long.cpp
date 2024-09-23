#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    string s;
    cin >> s;
    if(s.size() > 10) cout << s[0] << s.size()-2 << s.back() << endl;
    else cout << s << endl;
}

int main(){
    int t=1;
    cin >> t;
    while(t--) solve();

    return 0;
}