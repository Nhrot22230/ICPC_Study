#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>


using namespace std;


void solve(void){
    int n;
    cin >> n;
    int arr[n]{};
    for(int i=0; i<n; i++) cin >> arr[i];

    if(arr[0] > 1) cout << "NO" << endl;
    else    cout << "YES" << endl;
}


int main(void)
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}
