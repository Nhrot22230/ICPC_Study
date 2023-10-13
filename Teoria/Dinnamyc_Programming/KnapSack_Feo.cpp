#include <bits/stdc++.h>

using namespace std;

int knapSack_firstApproach(int w[], int v[], int i, int size, int C){
    if(i >= size) return 0;
    
    // decidir
    //cout << i << ") " << w[i] << "  " << v[i] << "  " << C << endl;
    if(C - w[i] < 0) return 0;
    return max(v[i] + knapSack_firstApproach(w, v, i+1, size, C - w[i]), knapSack_firstApproach(w, v, i+1, size, C));
}

int main(){
    int w[10] {1, 3, 4, 2,  8, 9, 11, 2, 4, 5};
    int v[10] {1, 4, 5, 7, 21, 1, 12, 4, 5, 1};
    int C = 13;

    cout << knapSack_firstApproach(w, v, 0, 10, C) << endl;

    return 0;
}