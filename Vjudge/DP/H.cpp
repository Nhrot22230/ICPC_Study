#include <bits/stdc++.h>
#define ll long long

using namespace std;

string s, t;


// dp(i, j) = lcs( s[i, n) , t[j, m) )
const int N = 3004;
bool done[N][N] {};
ll dp[N][N] {};


string frase = "";



ll DP(int i, int j){
    if(i == s.length() | j == t.length()) return 0;

    if(done[i][j]) return dp[i][j];

    done[i][j] = true;

    dp[i][j] = max(DP(i + 1, j), DP(i, j + 1));


    if(s[i] == t[j]){
        dp[i][j] = max(dp[i][j], 1 + DP(i + 1, j + 1));
    }

    return dp[i][j];
}

void reconstruct(int i, int j){
    if(i == s.length() | j == t.length()) return;

    if(DP(i, j) == DP(i + 1, j)){
        reconstruct(i + 1, j);
    }
    else if(DP(i, j) == DP(i, j + 1)){
        reconstruct(i, j + 1);
    }
    else if(s[i] == t[j] & DP(i, j) == 1 + DP(i + 1, j + 1)){
        frase += s[i];
        reconstruct(i + 1, j + 1);
    }
}

void Solve(void){
    cin >> s >> t;

    reconstruct(0,0);

    cout << frase << endl;
}

int main(){

    Solve();

    return 0;
}
