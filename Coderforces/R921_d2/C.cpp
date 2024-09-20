#include <bits/stdc++.h>

#define ll long long
#define ENDL '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int freq[30] {};

void Solve(void){
    int n, k, m;
    cin >> n >> k >> m;

    string s;
    cin >> s;

    for(int i=0; i<s.length(); i++){
        int idx = s[i] - 'a';
        freq[idx]++;
    }

    int min_idx = m + 1;
    int min_val = m + 1;
    for(int i=0; i<k; i++){
        if(min_val > freq[i]){
            min_val = freq[i];
            min_idx = i;
        }
    }

    if(min_val < n){
        cout << "NO" << endl;
        string ans = "";
        for(int i=0; i<n; i++) ans += (char)(min_idx + 'a');
        cout << ans << endl;
        return;
    }
    
    cout << "YES" << endl;
    for(int i=0; i<30; i++) freq[i] = 0;    
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