#include <bits/stdc++.h>
using namespace std;

int main(){
    int nRows;
    double poured, exceso;
    cin >> nRows >> poured;

    double tazas[100][100] {};
    tazas[0][0] = poured;
    exceso = poured - 1;
    for(int i=1; i<100 && exceso>0.0; i++){
        exceso = exceso/2;
        tazas[i][0] = exceso;
        tazas[i][i] = exceso;
        exceso--;
    }

    for(int i=1; i<100; i++){
        for(int j=1; j<i; j++){
            if(tazas[i-1][j-1] > 1.0) tazas[i][j] += (tazas[i-1][j-1]-1)/2;
            if(tazas[i-1][j] > 1.0) tazas[i][j] += (tazas[i-1][j]-1)/2;
        }
    }
    
    for(int i=0; i<nRows; i++){
        for(int j=0; j<=i; j++) cout << tazas[i][j] << " ";
        cout << endl;
    }


    return 0;
}