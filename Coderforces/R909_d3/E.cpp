#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    long long arr[n]{};
    for(int i=0; i<n; i++) cin >> arr[i];
    
    int min_index = n-1;
    int cont = 1;

    for(int i=n-2; i>=0; i--){
        if(arr[i] > arr[i+1]) break;
        min_index = i;
        cont++;
    }
    if(min_index > 0){
        for(int i=0; i<min_index; i++){
            if(arr[min_index] >= arr[i]){
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << n - cont << endl;
}

int main(){
    int t=1;
    cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
    
    return 0;
}