#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

pair<int,int> alumnos[5001]{};

int main(){
    ll n, cant1 = 0, cant2 = 0, cant3 = 0;
    cin >> n;

    for(int i=0; i<n; i++){ 
        cin >> alumnos[i].first;
        alumnos[i].second = i+1;

        if(alumnos[i].first == 1) cant1++;
        if(alumnos[i].first == 2) cant2++;
        if(alumnos[i].first == 3) cant3++;
    }
    sort(alumnos, alumnos + n);

    if(cant1*cant2*cant3 == 0){
        cout << 0 << endl;
        return 0;
    }

    int temp=1, index1=0, index2=0, index3=0;
    for(int i=0; i<n; i++){
        if(alumnos[i].first == temp){
            if(temp == 1) index1 = i;
            if(temp == 2) index2 = i;
            if(temp == 3) index3 = i;
            temp++;
        }
    }
    int tope = min(cant1, min(cant2,cant3) );
    cout << tope << endl;
    for(int i=0; i<tope; i++){
        cout << alumnos[index1 + i].second << " " << alumnos[index2 + i].second << " " << alumnos[index3 + i].second << endl;
    }
    cout << endl;

    return 0;
}