#include <bits/stdc++.h>

#define ENDL '\n'
#define ll long long
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);

using namespace std;

const ll MOD = 1e9 + 7;

int main(void){
    fastio;
    
    int n;
    cin >> n;

    int matrix[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c;
            cin >> c;

            matrix[i][j] = (i==0 & j==0 & c!='*');
            
            if(c == '*') continue;           
            
            if(i-1 >= 0) matrix[i][j] = (matrix[i][j] + matrix[i-1][j]) % MOD;
            if(j-1 >= 0) matrix[i][j] = (matrix[i][j] + matrix[i][j-1]) % MOD;
        }
    }

    cout << matrix[n-1][n-1] << ENDL;
    
    return 0;
}
