#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    string s1;
    cin >> s1;
    set<char> words;
    for(int i=0; i<s1.size(); i++)
        words.emplace(s1[i]);
    
    if(words.size()%2 == 0) cout << "CHAT WITH HER!" <<endl;
    else cout << "IGNORE HIM!" <<endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}