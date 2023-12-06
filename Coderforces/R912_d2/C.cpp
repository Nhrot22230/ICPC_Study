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
    int n;
    cin >> n;
    ll a[n]{};
    for(int i=0; i<n; i++) cin >> a[i];

    for(int i=n-1; i>0; i--) a[i-1] += a[i];

    ll sum = a[0];
    for(int i=1; i<n; i++) if(a[i] > 0) sum += a[i];
    cout << sum << endl;
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
