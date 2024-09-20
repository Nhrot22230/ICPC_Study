#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
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
    ll boxes[n]{};
    for(int i=0; i<n; i++) cin >> boxes[i];

    ll maxDiference = 0;

    for(int i=1; i<=n; i++){
        if(n%i) continue;
        ll tempMax = 0;
        ll tempMin = 0;
        tempMin = tempMin - 1;
        for(int j=n/i; j<=n; j+= n/i){
            ll temp = 0;
            for(int k=j - n/i; k<j; k++){
                temp += boxes[k];
            }
            tempMax = max(tempMax, temp);
            tempMin = min(tempMin, temp);
        }
        maxDiference = max(maxDiference, tempMax - tempMin);
    }

    cout << maxDiference << endl;
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
