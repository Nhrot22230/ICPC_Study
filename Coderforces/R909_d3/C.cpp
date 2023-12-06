#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0)

#define debug(x) cout << #x << "=" << x << endl
#define all(v) v.begin(), v.end()

#define PairII pair<int,int>
#define PairLL pair<ll,ll>
#define PairLI pair<ll,int>

//  3 4 5 6

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0; i<n; i++) cin >> a[i];

    int max_current, max_global;
    max_current = max_global = a[0];
    for(int i=1; i<n; i++){
        if(abs(a[i])%2 != abs(a[i-1])%2) max_current = max(a[i], max_current + a[i]);
        else max_current = a[i];
        
        max_global = max(max_global, max_current);
    }
    cout << max_global << endl;
}

int main(int argc, char const *argv[])
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
    
    return 0;
}
