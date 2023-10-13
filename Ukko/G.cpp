#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

bool backtracking(vector<int> &operantes, int pos, int resActual){
    if(resActual ==23 && pos == 5) return true;
    if(pos == 5) return false;
    if(backtracking(operantes, pos + 1, resActual + operantes[pos])) return true;
    if(backtracking(operantes, pos + 1, resActual - operantes[pos])) return true;
    if(backtracking(operantes, pos + 1, resActual * operantes[pos])) return true;


    return false;
}

bool permutaciones(vector<int> &ops, int i){
    if(i == 5){
        if(backtracking(ops, 1, ops[0])) return true;
        
        return false;
    }
    for(int j=i; j<5; j++){
        swap(ops[i], ops[j]);
        if(permutaciones(ops, i+1)) return true;
        swap(ops[i], ops[j]);
    }

    return false;
}

int main()
{
    vector<int> operantes(5);
    for(int i=0; i<5; i++) cin >> operantes[i];

    if(permutaciones(operantes, 0)) cout << "Posible" << endl;
    else cout << "Imposible" << endl;

    return 0;
}
