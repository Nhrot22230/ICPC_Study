#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    if (s1 == s2) cout << "YES" << endl;
    else cout << "NO" << endl; 
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}