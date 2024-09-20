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
    int n, x;
    cin >> n >> x;

    int a[n]{};
    for(int i=0; i<n; i++) cin >> a[i];

    int max_d = max(2*(x - a[n-1]), a[0]);

    for(int i=1; i<n; i++) max_d = max(max_d, a[i] - a[i-1]);
    

    cout << max_d << endl;
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
