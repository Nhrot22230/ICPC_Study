#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct Gato{
    ll llegada;
    ll index_reserva;
    ll demora;

    bool operator < (const struct Gato & cw) const{
        return llegada < cw.llegada; 
    }
};

struct CompareGato{
     bool operator()(const Gato &left, const Gato &right) {
        // Use '>' to prioritize elements in descending order based on the first element of the pair.
        return left.index_reserva > right.index_reserva;
    }
};

int main(){
    long long cant_gatos;
    cin >>cant_gatos;
    vector<Gato> gatos;
    ll llegada, demora;
    for(ll i=1; i<=cant_gatos; i++){
        cin >> llegada >> demora;
        Gato reserva = {llegada, i, demora};
        gatos.push_back(reserva);
    }
    sort(gatos.begin(), gatos.end());

    // cout << endl;
    // for(auto cat: gatos){
    //     cout << cat.llegada << "  " << cat.demora << "  " << cat.index_reserva << endl;
    // }
    // cout << endl;

    priority_queue<Gato, vector<Gato>, CompareGato> gatos_en_espera;
    int i=0, gatos_atendidos = 0;
    ll maxEspera = 0;
    ll tiempo = 0;

    while(gatos_atendidos<cant_gatos){
        if(gatos_en_espera.empty()){
            tiempo = max(tiempo, gatos[i].llegada);
        }
        while(i<cant_gatos && tiempo >= gatos[i].llegada){
            gatos_en_espera.push(gatos[i]);
            i++;
        }

        auto sgte_gato = gatos_en_espera.top();
        gatos_en_espera.pop();

        maxEspera = max(maxEspera, tiempo - sgte_gato.llegada);

        tiempo += sgte_gato.demora;
        gatos_atendidos++;
    }

    cout << maxEspera << endl;
    return 0;
}