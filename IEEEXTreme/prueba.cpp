#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;


int main(){
    int n; cin >> n;
    n--;
    stack<int>currVisibles;
    int frontPerson, curPerson;
    cin >> curPerson;
    int suma = 0;
    while(n--){
        frontPerson = curPerson;
        cin >> curPerson;
        while(not currVisibles.empty() && frontPerson >= currVisibles.top()){
            currVisibles.pop();
        }
        currVisibles.push(frontPerson);
        cout << "Vibles para " << curPerson << ": "<< currVisibles.size() << endl;
        suma += currVisibles.size();
    }
    cout << suma << endl;
    return 0;
}