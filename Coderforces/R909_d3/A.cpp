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
    int num;
    cin >> num;
    if(num%3) cout << "First" << endl;
    else cout << "Second" << endl;
    
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
