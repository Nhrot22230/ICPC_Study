#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    int Anton = 0;
    char letra;
    for(int i=0; i<n; i++){
        cin >> letra;
        if(letra == 'A') Anton++;
        else Anton--;
    }

    if(Anton>0) cout << "Anton" << endl;
    else if(Anton == 0) cout << "Friendship" << endl;
    else cout << "Danik" << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}