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

//5 0 4 0 3 0 1
void Solve(){
    int n;
    cin >> n;
    ll c[n+3] {};
    for(int i=0; i<n; i++) cin >> c[i];
    int end=n-1;
    for(; end>=0; end--) if(c[end]) break;
   
   
    ll cant_tp = 0;
    ll max_temp = 1;
    ll min_temp = 1;
    bool peak = false;
    
    for(int i=0; i<=end; i++){
        if(c[i]==0){
            max_temp=min_temp=1;
            cant_tp++;
            while(c[i]==0) i++;
        }

        if(c[i] > max_temp){
            max_temp = c[i];
            peak = true;
        }
        if(c[i] < max_temp){
            if(peak){
                cant_tp += max_temp - min_temp;
                peak = false;
            }
            min_temp = c[i];
            max_temp = min_temp;
        }

        if((c[i+1] == 0 || i == end) && peak) cant_tp += max_temp - min_temp;
    }
    cout << cant_tp << endl;
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
