#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string enemy_pawns;
    string my_pawns;

    cin >> enemy_pawns;
    cin >> my_pawns;

    int cont = 0;
    for(int i=0; i<n;i++){
        if(my_pawns[i] == '1' && enemy_pawns[i] == '0') {
            enemy_pawns[i] = '2';
            my_pawns[i] = '0';
            cont ++;
        }
    }
    for(int i=0; i<n-1; i++){
        if(my_pawns[i] == '1' && my_pawns[i+1] == '1'){
            if(enemy_pawns[i] == '1' && enemy_pawns[i+1] == '1'){
                enemy_pawns[i] = '2';
                enemy_pawns[i+1] = '2';
                my_pawns[i] = '0';
                my_pawns[i+1] = '0';
                cont++; cont++;
                i++;
            }
        }
        if(my_pawns[i] == '0' && my_pawns[i+1] == '1'){
            if(enemy_pawns[i] == '1' && enemy_pawns[i+1] == '1'){
                enemy_pawns[i] = '2';
                my_pawns[i+1] = '0';
                cont++;
                i++;
            }
        }
    }

    for(int i=0; i<n; i++){
        if(i-1>=0 && my_pawns[i] == '1' && enemy_pawns[i-1] == '1'){
            enemy_pawns[i-1] = '2';
            my_pawns[i] = '0';
            cont++;
        }
        if(i+1<n && my_pawns[i] == '1' && enemy_pawns[i+1] == '1'){
            enemy_pawns[i+1] = '2';
            my_pawns[i] = '0';
            cont++;
        }
        
    }
    // cout << enemy_pawns << endl;
    // cout << my_pawns << endl;
    cout << cont << endl;
}


int main(int argc, char const *argv[])
{
    /* code */
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
