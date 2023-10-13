#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;


int main(){
    int n;
    cin >> n;
    int nextPrice = 0, curPrice=0;
    int nextMeat = 0, gastoTotal = 0;
    
    cin >> nextMeat >> curPrice;
    gastoTotal += nextMeat*curPrice;
    n--;
    while(n--){
        cin >> nextMeat >> nextPrice;
        if(curPrice > nextPrice) curPrice = nextPrice;
        
        gastoTotal += nextMeat*curPrice;
    }

    cout << gastoTotal << endl;
    return 0;
}