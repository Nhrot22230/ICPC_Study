#include <bits/stdc++.h>
    
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
    
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, a, sumpos = 0, sumneg = 0;
    cin>>n>>m;
    for(int i=0; i<n;i++){
        cin>>a;
        if(a==1) sumpos += a;
        else sumneg +=a;
    }
    if(((-1)*sumneg) <= sumpos) a = (-1)*sumneg;
    else a = sumpos;
    int l,r,dif;
    for(int i=0;i<m;i++){
        cin>>l>>r;
        dif = r-l+1;
        if((dif%2==0) && (dif/2)<=a) cout<<1;
        else cout<<0;
        cout<<'\n';
    }
    return 0;
}