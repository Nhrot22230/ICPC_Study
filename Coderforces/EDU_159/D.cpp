#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0);

#define debug(x) cout << #x << " = " << x << endl
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pii pair<int,int>

#define vi vector<int>
#define vl vector<ll>

using namespace std;

void insertarOrdenado(stack<int> &pila, int newElement){
    if(pila.empty()){
        pila.push(newElement);
        return;
    }

    if(newElement > pila.top()){
        int aux = pila.top(); pila.pop();
        insertarOrdenado(pila, newElement);
        pila.push(aux);
    }
    else pila.push(newElement);
}

void mostrarPila(stack<int> &pila){
    if(pila.empty()) {
        cout << endl; return;
    }
    cout << pila.top() << " - ";
    pila.pop();
    mostrarPila(pila);
}

void Solve(){
    stack<int> pila;
    for(int i=1; i<15; i++) pila.push(15 - i);

    insertarOrdenado(pila, 7);
    mostrarPila(pila);

}

int main(void)
{
    fastio;
    int t=1;
    //cin >> t;
    while (t--)
    {
        /* code */
        Solve();
    }
    
    return 0;
}
