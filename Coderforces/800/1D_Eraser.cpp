#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int n, k;
    string s;
    int cont=0;
    cin >> n >> k >> s;
    for(int i=0; i<n; i++){
        if(s[i] == 'B'){
            cont++;
            for(int j=0; j<k && j+i < n; j++) s[i+j] = 'W';
        }
    }
    cout << cont << endl;
}

int main(){
    int t=1;
    cin >> t;
    while(t--) solve();

    return 0;
}