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
    int N, W;
    cin >> N >> W;
    
    int w[N]{}, v[N]{};
    for(int i=0; i<N; i++) cin >> w[i] >> v[i];
    
    cout << knapSack_firstApproach(w, v, 0, N, W) << endl;
    return 0;
}