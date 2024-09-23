
#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool dp[1400] {};

ll numSquareSum(ll n)
{
    ll squareSum = 0;
    while (n) {
        squareSum += (n % 10) * (n % 10);
        n /= 10;
    }
    return squareSum;
}

int nextNumber(int n){
    int newNumber = 0;
    while(n!=0){
        int num = n%10;
        newNumber += num*num;
        n = n/10;
    }
    return newNumber;
}

bool isHappy(int n) {
    unordered_set<int> set;
    while(n!=1 && !set.count(n)){
        set.insert(n);
        n = nextNumber(n);
    }
    return n==1;
}

void fill_dp(){
    for(int i=1; i<=1296; i++){
        dp[i] = isHappy(i);
    }
}

int main(){
    fill_dp();
    ll a, b;
    cin >> a >> b;
    ll cont = 0;

    for(; a<=b; a++){
        if(dp[numSquareSum(a)]) cont++;
    }

    cout << cont << endl;
    return 0;
}