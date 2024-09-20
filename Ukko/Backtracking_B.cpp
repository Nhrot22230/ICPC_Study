#include<bits/stdc++.h>

using namespace std;

bool solve(const string& grabado, string& frase,const int cantMax, int cantAbiertos, int cantCerrados, int idx) {
    if(cantAbiertos == cantCerrados && cantAbiertos + cantCerrados == cantMax) {
        cout << frase << '\n';
        return true;
    }
    if(cantCerrados > cantAbiertos) return false;
    if(cantAbiertos + cantCerrados > cantMax) return false;
    if(cantAbiertos>0 && cantAbiertos==cantCerrados && cantAbiertos+cantCerrados<cantMax) return false;

    if(grabado[idx] == '?'){
        frase.push_back(')');
        if(solve(grabado, frase, cantMax, cantAbiertos, cantCerrados + 1, idx + 1)){
            return true;
        }else{
            frase.resize(idx);
            frase.push_back('(');
            return solve(grabado, frase, cantMax, cantAbiertos + 1, cantCerrados, idx + 1);
        }
    }
    else{
        frase.push_back(grabado[idx]);
        return solve(grabado, frase, cantMax,  cantAbiertos + (grabado[idx] == '('), cantCerrados + (grabado[idx] == ')'), idx +1);
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string grabado;
    cin >> n >> grabado;

    string frase;
    if(!solve(grabado, frase, n, 0, 0, 0)) {
        cout << ":(" << '\n';
    }

    return 0;
}
