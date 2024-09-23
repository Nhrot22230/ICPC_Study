#include <bits/stdc++.h>

#define ll long long
#define ENDL '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

void Solve(void){
    int n, k;

    cin >> n >> k;

    string ans = "";

    for(int i=0; i<k; i++){
        char letra = 'a' + i;
        ans += letra;
    }

    string temp = ans;
    for(int i=1; i<n; i++){
        next_permutation(temp.begin(), temp.end());
        ans += temp;
    }

    cout << ans << endl;
}

int main(void){
    fastio;
    
    int t = 1;

    cin >> t;
    
    while (t--)
    {
        /* code */
        Solve();
    }
    

    return 0;
}