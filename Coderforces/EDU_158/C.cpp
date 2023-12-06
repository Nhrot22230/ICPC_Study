#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0);

#define debug(x) cout << #x << " = " << x << endl
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pii pair<int,int>

#define vi vector<int>
#define vll vector<ll>

using namespace std;

void Solve(){
    int n;
    cin >> n;
    ll a[n]{};
    ll maxValue = 0, minValue = 1e10;

    for(int i=0;i<n; i++) cin >> a[i];
    for(int i=0;i<n; i++) maxValue = max(maxValue,a[i]), minValue = min(minValue, a[i]);
 
    vi sol;
    while(maxValue != minValue){
        sol.push_back(minValue%2);
        minValue = (minValue + sol.back())/2;
        maxValue = (maxValue + sol.back())/2;
    }

    if((int)sol.size() > n) cout << (int)sol.size() << endl;
    else{
        if((int) sol.size() == 0){
            cout << 0 << endl;
        }
        else{
            cout << (int) sol.size() << endl;
            for(int v : sol) cout << v << " ";
            cout << endl;
        }
    }
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
