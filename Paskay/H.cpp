#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

ll calc_patrones(ll x){
    ll n = (x - x%2)/2;

    return n*(x-n+1) + x%2;
}

vector<ll> fuerza_brutal(ll cant_escalones){
	vector<ll> solution;
	ll target = calc_patrones(cant_escalones);
	
    for(ll num=1; num<(1<<cant_escalones); num++){
        ll pares_validos=0;
		for(ll i=0; i<cant_escalones; i++){
            ll cont_rojo=0;
			for(ll j=i; j<cant_escalones; j++){
                if((num>>j)&1) cont_rojo++;
                if(cont_rojo&1) pares_validos++;
			}
		}
		if(target==pares_validos){
			solution.push_back(num);
            if(solution.size() == 100) break;
		}
	}

	return solution;
}

int main()
{
    ll cant_escalones;
    cin >> cant_escalones;  
    cout << calc_patrones(cant_escalones) << endl;
    
    if(cant_escalones<=30){
        vector<ll> solution = fuerza_brutal(cant_escalones);
        for(ll i=0; i<solution.size(); i++){
            string frase = "";
            for(ll j=0;j<cant_escalones;j++){
                if(solution[i] >> j & 1) frase += 'r';
                else frase += 'b';
            }
            reverse(frase.begin(), frase.end());
            cout << frase << endl;
        }
    }
    else{
        //exp: bbbbbbbbbbbbbbbbbbbbbbbbrbbbbbbbbbbbbbbbbbbbbbbbbbr
        //out: bbbbbbbbbbbbbbbbbbbbbbbbbrbbbbbbbbbbbbbbbbbbbbbbbbr
        //     bbbbbbbbbbbbbbbbbbbbbbbbrbbbbbbbbbbbbbbbbbbbbbbbbbr
        string frase(cant_escalones, 'b');
        int mitad = cant_escalones/2;
        frase[mitad] = 'r';
        cout << frase << endl;

        int restantes = 99;
        frase[mitad] = 'b';
        frase[mitad - 1] = 'r';
        if(cant_escalones%2 == 0){
            cout << frase << endl;
            restantes--;
        }
        int i=cant_escalones-1, j=cant_escalones-2;
        frase[i] = 'r';
        restantes--;
        cout << frase << endl;
        while(restantes && mitad < i){
            frase[i] = 'r';
            frase[j] = 'r';
            cout << frase << endl;
            frase[i] = 'b';
            restantes--;
            i--; j--;
        }
        vector<ll> copiar_ultimos;
        if(cant_escalones&1)copiar_ultimos = fuerza_brutal(29);
        else copiar_ultimos = fuerza_brutal(30);
        
        frase[mitad + 1] = 'b';
        frase[mitad] = 'b';
        frase[mitad - 1] = 'b';
        frase[mitad - 2] = 'r';
        

        for(i = 17 - cant_escalones%2; restantes && i<copiar_ultimos.size();i++){
            for(j = 0; j<14; j++){
                if(copiar_ultimos[i]>>j&1) frase[cant_escalones-1-j] = 'r';
                else frase[cant_escalones-1-j] = 'b';
            }
            cout << frase << endl;
            restantes--;
        }
    }
    return 0;
}
