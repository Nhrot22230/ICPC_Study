#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;



int main(){
    int n;
    int first_year = 1867;
    cin >> n;
    int cont = 0;
    for(int i=first_year + 1; i<=first_year+n; i++){
        if(i%400 == 0){
            cont++;
        }
        else if(i%100 != 0 && i%4 == 0){
            cont++;
        }
        cont++;
    }
    // s m t w t f s

    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    cout << days[cont%7] << endl;
    return 0;
}