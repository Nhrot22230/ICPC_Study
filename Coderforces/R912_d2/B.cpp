#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0);

#define debug(x) cout << #x << " = " << x << endl
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pii pair<int,int>

#define vi vector<int>
#define vl vector<ll>

using namespace std;

/*
M[0][i] = a[0] | a[i];

*/

void Solve(){
    int n;
    cin >> n;
    ull M[n][n];
    ull a[n]{};

    for(int i=0; i<n; i++){
        a[i] = 0 - 1;
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> M[i][j];

    if(n == 1){
        cout << "YES" << endl;
        cout << 1 << endl;
        return;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            a[i] = a[i] & M[i][j];
        }
    }


    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(i == j) continue;
            if(M[i][j] != (a[i] | a[j])){
                cout << "NO" << endl;
                return;
            }
        }
    
    cout << "YES" << endl;
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
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
