#include <bits/stdc++.h>

using namespace std;

void Solve(){
    int n;
    cin >> n;
    int M[n][n];
    int used_row[n+1][n+1] {};
    int used_col[n+1][n+1] {};

    int k = 0, r = 0, c = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> M[i][j];
            if(i == j) k += M[i][j];

            used_row[i][M[i][j]]++;
            used_col[j][M[i][j]]++;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(used_row[i][M[i][j]] > 1){
                r++; break;
            }
        }
    }

    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            if(used_col[j][M[i][j]] > 1){
                c++; break;
            }
        }
    }

    cout << k << ' ' << r << ' ' << c << endl;
}

int main(int argc, char const *argv[])
{
    int t=1;
    cin >> t;
    for(int i=1; i<=t; i++){
        cout << "Case #" << i << ": ";
        Solve();
    }
    
    return 0;
}
