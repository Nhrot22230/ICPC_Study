#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >>n; cin.ignore();
    while(n--){
        
        string line;
        getline(cin, line);
        sort(line.begin(), line.end());
        line[line.length() - 1] = 0;
        char letra = 0, masLetra = 0;
        int cont = 0, maxCont = 0;
        for(int i=0; i<line.size(); i++){
            if(line[i] == ' ') continue;
            if(letra != line[i]){
                if(cont > maxCont){
                    masLetra = letra;
                    maxCont = cont;
                }
                cont = 0;
            }
            cont ++;
        }
        cout << line << " -> ";
        cout << toupper(masLetra) << endl;
    }

    return 0;
}
