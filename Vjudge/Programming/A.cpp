#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main(){
    ll sum, n;
    cin >> sum;
    n = sum;
    sum = sum*(sum + 1);
    sum = sum/2;
    n--;
    while(n--){
        ll num;
        cin >> num;
        sum = sum - num;
    }
    cout << sum << endl;

    return 0;
}