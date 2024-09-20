#include <bits/stdc++.h>
    
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
    
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,k,a;
    multiset<int> m;
    vector<int> v;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a;
        m.insert(a);
        if(find(v.begin(),v.end(),a) == v.end()) v.push_back(a);
    }
    int cant,plat=0;
    for(vector<int>::iterator it = v.begin(); it!=v.end();it++){
        cant = (int)ceil((double)m.count(*it)/k);
        if(cant>=plat) plat = cant;
    }
    cout<<((v.size()*k*plat)-m.size())<<'\n';
    return 0;
}