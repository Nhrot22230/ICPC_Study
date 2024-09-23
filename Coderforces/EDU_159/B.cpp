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
    ll n, P, l, t;
    cin >> n >> P >> l >> t;

    ll cantTask = 1;
    if(n-1 > 0) cantTask = (n-1)/7 + 1;

    ll cantStudy = 1e12;
    ll curPoints = 0;

    ll left = 1, right = n;

    while(right - left > 1){
        ll med = left + (right - left)/2;
        
        curPoints = l*med;
        if(med*2 >= cantTask) curPoints += cantTask*t;
        else curPoints += med*2*t;

        if(curPoints == P){
            left = med;
            break;
        }
        if(curPoints > P) right = med - 1;
        else if(curPoints < P) left = med;
    }

    cout << n - left << "--" << n - right << endl;
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
