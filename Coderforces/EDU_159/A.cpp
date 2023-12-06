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
    char s[n+1]{};
    cin >> s;

    for(int i=0; i<n; i++){
        if(s[i] == '0'){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
