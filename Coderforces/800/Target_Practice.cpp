#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

int calc(int i, int j, int &points){
    int sumado = 0;
    if  (i==0 || i==9) {points++; sumado++;}
    if( (i==1 || i==8) && (j>=1 && j<=8) ) {points+=2; sumado++;}
    if( (i==2 || i==7) && (j>=2 && j<=7) ) {points+=3; sumado++;}
    if( (i==3 || i==6) && (j>=3 && j<=6) ) {points+=4; sumado++;}
    if( (i==4 || i==5) && (j>=4 && j<=5) ) {points+=5; sumado++;}

    return sumado;
}

void solve(){
    char letra;
    int points = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> letra;
            if(letra == 'X'){
                if(calc(i, j, points) == 0) calc(j, i, points);
            }
        }
    }
    cout << points << endl;
}

int main(){
    int t=1;
    cin >> t;
    while(t--) solve();

    return 0;
}