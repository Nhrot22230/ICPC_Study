#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int n, t;
    string fila;
    cin >> n >> t >> fila;
    while(t--){
        for(int i=0; i<n-1; i++){
            if(fila[i] == 'B' && fila[i+1] == 'G') {
                fila[i+1] = 'B'; fila[i] = 'G';
                i++;
            }
        }
    }
    cout << fila << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}