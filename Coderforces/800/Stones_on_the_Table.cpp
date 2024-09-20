#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int n; cin >> n;
    string s1;
    cin >> s1;
    int ans=0;
    for(int i=0; i<s1.size()-1; i++)
        ans += s1[i] == s1[i+1];

    cout << ans << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}