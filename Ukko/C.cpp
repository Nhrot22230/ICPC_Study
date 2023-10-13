#include <bits/stdc++.h>

using namespace std;
    
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    long long n,n1, max_Peso;
    cin >> n >> max_Peso;
    n1=n;
    vector<long long> musica;
    long long num1, num2, sum=0, minSum=0;
    while(n--){
        cin >> num1 >> num2;
        musica.push_back(num2-num1);
        sum+=num1;
    }
    sort(musica.begin(), musica.end());
    long long cont=0;
    while(sum>max_Peso && cont<n1){
        sum+=musica[cont];
        cont++;
    }
    if(cont == n1 && sum > max_Peso) cout << -1 << endl;
    else cout << cont << endl;
    return 0;
}