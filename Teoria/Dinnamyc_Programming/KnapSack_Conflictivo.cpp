#include <bits/stdc++.h>

using namespace std;

int corta_arbol(int v[], int s[], int e[], int l[], int i, int size){
    if(i >= size) return 0;
    
    for(int j=s[i]; j<e[i]-1; j++) if(l[j]) 
        return corta_arbol(v,s,e,l,i+1,size);
    
    int l_copy[20] {};

    for(int j=0; j<20;j++) 
        l_copy[j] = l[j];
    for(int j=s[i]; j<=e[i];j++) 
        l_copy[j-1] = 1;

    return max(v[i] + corta_arbol(v,s,e,l_copy,i+1,size), 
               corta_arbol(v,s,e,l,i+1,size));
}

int main(){
    int v[4]  {30, 40, 80, 100};
    int s[4]  {5, 2, 6, 4};
    int e[4]  {10, 4, 12, 15};
    
    int l[20] {};

    cout << corta_arbol(v, s, e, l, 0, 4) << endl;
    return 0;
}
