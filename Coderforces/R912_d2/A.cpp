#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0);

#define debug(x) cout << #x << " = " << x << endl
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pii pair<int,int>

#define vi vector<int>
#define vl vector<ll>

using namespace std;

void Solve(){
    int n, k;
    cin >> n >> k;
    ll a[n] {};
    for(int i=0; i<n; i++) cin >> a[i];
    
    bool isSorted = true;
    
    for(int i=1; i<n; i++){
        if(a[i] < a[i-1]){
            isSorted = false;
            break;
        }
    }

    if(k>1 || (k==1 && isSorted)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(void)
{
    fastio;
    int t=1;
    cin >> t;
    while (t--)
    {
        /* code */
        Solve();
    }
    
    return 0;
}
