#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    long n;
    string str;
    string new_str;
    cin>>n;
    if(n%2){
        cout<<":(";
        return;
    } 
    cin>>str;
    long counta=0;
    long countc=0;
    for(char x:str){
        if(x=='(') counta++;
        if(x==')') countc++;
    }
    if(counta>n/2 or countc>n/2){
        cout<<":(";
        return;
    } 
    counta=n/2-counta;
    long suma=0;
    long counter=0;
    for(char x:str){
        counter++;
        if(x=='('){
            new_str+=x;
            suma++;
        } else if(x==')'){
            new_str+=x;
            suma--;
        } else if(x=='?'){
            if(counta>0){
                new_str+='(';
                suma++;
                counta--;
            } else {
                new_str+=')';
                suma--;
            }
        }
        if(suma<1 and (counter<n)){
            cout<<":(";
            return;
        } else if(counter==n){
            cout<<new_str;
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }

    return 0;
}