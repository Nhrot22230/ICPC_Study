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
    char s[n + 1]{};
    
    for(int i=0; i<n; i++) cin >> s[i];

    int begin = 0, end=n-1;
    for(; begin <n; begin++) if(s[begin] == 'A') break;
    for(; end>=0; end--) if(s[end] == 'B') break;

    int cantA = 0, cantB = 0;
    for(int i=begin; i<=end; i++){
        if(s[i] == 'A') cantA++;
        else cantB++;
    }
    if(cantA == 0 && cantB == 0) cout << 0 << endl;
    else cout << cantB + cantA - 1 << endl;
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
