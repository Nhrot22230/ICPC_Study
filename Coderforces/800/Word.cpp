#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    string s1;
    cin >> s1;
    int cantMayus = 0;
    for(char c : s1) if(c <= 'Z') cantMayus++;

    if(cantMayus*2>s1.size()){
        for(int i=0; i<s1.size(); i++) s1[i] = toupper(s1[i]);
    }else{
        for(int i=0; i<s1.size(); i++) s1[i] = tolower(s1[i]);
    }
    cout << s1 << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}