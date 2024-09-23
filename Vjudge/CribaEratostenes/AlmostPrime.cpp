#include <iostream>
using namespace std;

bool is_almostPrime(int arrPrimos[], int cantPrimos, int num){
    int cont=0;
    for(int i=0; i<cantPrimos; i++){
        if(num%arrPrimos[i] == 0){
            cont++;
        }
    }
    return cont==2;
}

int main(){

    int n; 
    cin>>n;

    bool arrMarcado[n+1] {};
    int arrPrimos[n+1] {};
    int contPrimos=0;
    
    for(int i=2; i*i<=n;i++){
        if(not arrMarcado[i-2]){
            for(int j=i; j<=n/i; j++){
                arrMarcado[i*j-2] = true;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(not arrMarcado[i-2]){
            arrPrimos[contPrimos] = i;
            contPrimos++;
        }
    }
    int cont=0;
    for(int i=6; i<=n; i++){
        if(is_almostPrime(arrPrimos, contPrimos, i))
            cont++;
    }
    cout << cont << endl;
    return 0;
}