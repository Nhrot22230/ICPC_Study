#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

int main(){

    int N, H, W;
    cin >> N >> H >> W;

    char r_ida, r_vuelta;
    char u_ida, u_vuelta;

    while(N--){
        cin >> r_ida >> r_vuelta;

        if(r_ida == 'N') u_ida = W==0 ? 'Y' : 'N';
        if(r_ida == 'Y') u_ida = H>0 ? 'Y' : 'N';
        if(u_ida == 'Y'){
            H--; W++;
        }

        if(r_vuelta == 'N') u_vuelta = H==0 ? 'Y' : 'N';
        if(r_vuelta == 'Y') u_vuelta = W>0 ? 'Y' : 'N';
        
        if(u_vuelta == 'Y'){
            W--; H++;
        }
        cout << u_ida << " " << u_vuelta << endl;
    }
    return 0;
}