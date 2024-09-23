#include <bits/stdc++.h>
using namespace std;

int r[1000] {};

int memorized_rod_cut(int p[], int n){
    int q=0;
    for(int j=1; j<=n; j++){
        q = 0;
        for(int i=1; i<=j; i++){
            q = max(q, p[i-1] + r[j - i]);
        }
        r[j] = q;
    }
    return r[n];
}

int rod_cut(int arreglo[], int maxData){
    if(maxData <= 0) return 0;

    int maxValue = 0;
    for (int i = 0; i < maxData; i++)
    {
        maxValue = max(maxValue, arreglo[i] + rod_cut(arreglo, maxData - i - 1));
    }
    return maxValue;    
}

int main(){
    //         1  2  3  4   5   6   7   8   9  10
    int p[10] {1, 5, 8, 9, 10, 17, 18, 20, 24, 30};

    for (int i = 1; i <= 10; i++)
    {
        cout << rod_cut(p, i) << "  ";
    }
    cout << endl;
    

    for (int i = 1; i <= 10; i++)
    {
        cout << memorized_rod_cut(p, i) << "  ";
    }
    cout << endl;
    
    return 0;
}
