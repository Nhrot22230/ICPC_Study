#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n] {};
    int curProduct = 1, maxProd = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        curProduct *= arr[i];
    }

    for(int i=0; i<n; i++){
        
    }

}

int main(){
    int t=1;
    cin >> t;
    while(t--) solve();

    return 0;
}