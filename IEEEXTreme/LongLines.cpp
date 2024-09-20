#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

ll calc(ll h, ll a, ll c, ll q){
    return (a*h + c)%q;
}

int main(){
    ll n, h_0, a, c, q;
    cin >> n >> h_0 >> a >> c >> q;
    ll currPerson = h_0;

    stack<ll>currVisibles;
    n--;
    ll suma = 0;
    while(n--){
        ll previous = currPerson;
        currPerson = calc(currPerson, a, c, q);
        while(not currVisibles.empty() && previous >= currVisibles.top()){
            currVisibles.pop();
        }
        currVisibles.push(previous);
        suma += currVisibles.size();
    }
    cout << suma << endl;
    return 0;
}