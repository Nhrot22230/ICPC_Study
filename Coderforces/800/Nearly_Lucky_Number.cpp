#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

bool is_lucky_number(ll n){
    if(n == 0) return false;
    while(n){
        if(n%10 != 4 && n%10 != 7) return false;

        n = n/10;
    }
    return true;
}

bool is_nearly_lucky_number(ll n){
    ll cont = 0;
    while(n){
        if(n%10 == 4 || n%10 == 7) cont++;
        n = n/10;
    }

    return is_lucky_number(cont);
}

int main()
{
    
    ll n;
    cin >> n;
    if(is_nearly_lucky_number(n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}