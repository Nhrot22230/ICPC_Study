#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int V = 30;
bool arrVisitados[V]{};

bool cycle_detector(vector<vector<int>> &grafo, int nodo, int anterior){
    if(arrVisitados[nodo]){
        return true;
    }
    arrVisitados[nodo] = true;
    bool ciclo_detectado = false;

    for(int v: grafo[nodo]){
        if(v == anterior) continue;
        ciclo_detectado = ciclo_detectado || cycle_detector(grafo, v, nodo);
    }

    return ciclo_detectado;
}

void dfs(vector<vector<int>> &grafo, int nodo, int anterior, string &result){
    result += char(nodo + 'a');
    for(int v : grafo[nodo]){
        if(v == anterior) continue;
        dfs(grafo, v, nodo, result);
    }
}


void solve(){
    string cad, result = "";
    cin >> cad;
    vector<vector<int>> grafo(V);
    bool used[V] {};

    used[ cad[0] - 'a' ] = true;
    for(int i=1; i<cad.length(); i++){
        if(cad[i] == cad[i-1]) continue;
        bool tiene = false;
        
        for(int v : grafo[ cad[i] - 'a' ]){
            if(v == int(cad[i-1] - 'a') ) tiene = true;
        }

        if(tiene) continue;
        grafo[cad[i] - 'a'].push_back( cad[i-1] - 'a' );
        grafo[cad[i - 1] - 'a'].push_back( cad[i] - 'a' );
        used[cad[i] - 'a'] = true;
    }

    bool flag_posible = true;
    int sospechoso = -1;
    for (int i = 0; i < 26; i++){
        if(grafo[i].size() > 2) {
            flag_posible = false;
            break;
        }
        if(grafo[i].size() == 1) sospechoso = i;
    }

    for(int i=0; i<26; i++){
        if(used[i]){
            flag_posible = flag_posible && not cycle_detector(grafo, i, -1);
            break;
        }
    }


    // for (int i = 0; i < 26; i++){
    //     if(grafo[i].size() < 1) continue;
    //     cout << (char)(i + 'a') << " ->";
    //     for(int v : grafo[i]){
    //         cout << "  " << (char)(v + 'a');
    //     }
    //     cout << endl;
    // }

    if(flag_posible){
        cout << "YES" << endl;
        if(sospechoso >=0 ) dfs(grafo, sospechoso, -1, result);
        for(int i=0; i<26; i++) if(grafo[i].size() == 0) result += (char)(i + 'a');
        cout << result << endl;
    }
    else{
        cout << "NO" << endl;
    }


    for(int i=0; i<26; i++) arrVisitados[i] = false;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}
