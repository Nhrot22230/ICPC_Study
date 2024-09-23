#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int calcular_posibilidades(int &cant_neg_1, vector<int> &cola_notas){
    if(cola_notas.size() == 3) cola_notas.push_back(cola_notas[0]);

    if(cola_notas[0] != cola_notas[3]){
        if(cola_notas[0] == -1){
            cola_notas[0] = cola_notas[3];
            cant_neg_1--;
        }
        else if(cola_notas[3] == -1) cola_notas[3] = cola_notas[0];
        else return 0;
    }

    if(cola_notas[0] == cola_notas[1] && (cola_notas[0] == 0))
    return 0;
    if(cola_notas[0] == cola_notas[2] && (cola_notas[0] == 0))
    return 0;
    if(cola_notas[2] == cola_notas[1] && (cola_notas[1] == 0))
    return 0;

    if( (cola_notas[0] + cola_notas[1] > 3) || 
        (cola_notas[1] + cola_notas[2] > 3) || 
        (cola_notas[0] + cola_notas[2] > 3) || 
        (cola_notas[0] + cola_notas[1] + cola_notas[2] > 3)){
        return 0;
    }
    if(cant_neg_1 == 1){
        if(cola_notas[0] == -1) cola_notas[0] = 3 - (cola_notas[1] + cola_notas[2]);
        if(cola_notas[1] == -1) cola_notas[1] = 3 - (cola_notas[0] + cola_notas[2]);
        if(cola_notas[2] == -1) cola_notas[2] = 3 - (cola_notas[1] + cola_notas[0]);

        cant_neg_1--;
        return 1;
    }
    if(cant_neg_1 == 2){
        if(cola_notas[0] == 0 || cola_notas[1] == 0 || cola_notas[2] == 0 ) return 2;
        if(cola_notas[0] == 2 || cola_notas[1] == 2 || cola_notas[2] == 2 ) return 2;
        if(cola_notas[0] == 1 || cola_notas[1] == 1 || cola_notas[2] == 1 ) return 3;
    }
    if(cant_neg_1 == 3) return 7;

    if(cant_neg_1 == 0) return 1;

    return 0;
}

int main(){
    
    int total_notas;
    cin >> total_notas;
    vector<int> cola_notas;
    int nota, cant_neg_1 = 0;

    cin>>nota;
    if(nota == -1) cant_neg_1++;
    cola_notas.push_back(nota);
    cin>>nota;
    if(nota == -1) cant_neg_1++;
    cola_notas.push_back(nota);
    cin>>nota;
    if(nota == -1) cant_neg_1++;
    cola_notas.push_back(nota);
    
    int posibilidades = 7;
    for(int i=2; i<total_notas; i++){
        if( i+1 < total_notas){
            cin >> nota;
            cola_notas.push_back(nota);
        }

        int temp = calcular_posibilidades(cant_neg_1, cola_notas);

        // cout << "No definidos = " << cant_neg_1 << ":   ";
        // cout << cola_notas[0] << "  ";
        // cout << cola_notas[1] << "  ";
        // cout << cola_notas[2] << "  ";
        // cout << cola_notas[3] << " -> " << temp << endl;
        
        posibilidades = min(posibilidades, temp);
        if(cola_notas[0] == -1) cant_neg_1--;
        if(cola_notas[3] == -1) cant_neg_1++;
        cola_notas.erase(cola_notas.begin());
    }

    cout << posibilidades << endl;
    return 0;
}