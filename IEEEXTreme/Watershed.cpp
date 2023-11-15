#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    pair<double,int> matrix[n][m] {};
    
    vector< pair<int, pair<int,int> > > val_coords;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j].second;
            matrix[i][j].first = 1;

            val_coords.push_back( {matrix[i][j].second, {i, j} });
        }
    }

    sort(val_coords.begin(), val_coords.end());
    
    reverse(val_coords.begin(), val_coords.end());

    double maxValue = 0;
    for(auto val_coord : val_coords  ){
        int i = val_coord.second.first;
        int j = val_coord.second.second;

        int contCompartir = 0;
        if(i-1 >=0 && matrix[i-1][j].second < matrix[i][j].second) contCompartir++;
        if(i+1 < n && matrix[i+1][j].second < matrix[i][j].second) contCompartir++;
        if(j-1 >=0 && matrix[i][j-1].second < matrix[i][j].second) contCompartir++;
        if(j+1 < m && matrix[i][j+1].second < matrix[i][j].second) contCompartir++;
        
        if(i-1 >=0 && matrix[i-1][j].second < matrix[i][j].second) matrix[i-1][j].first += matrix[i][j].first/contCompartir;
        if(i+1 < n && matrix[i+1][j].second < matrix[i][j].second) matrix[i+1][j].first += matrix[i][j].first/contCompartir;
        if(j-1 >=0 && matrix[i][j-1].second < matrix[i][j].second) matrix[i][j-1].first += matrix[i][j].first/contCompartir;
        if(j+1 < m && matrix[i][j+1].second < matrix[i][j].second) matrix[i][j+1].first += matrix[i][j].first/contCompartir;

        if(contCompartir) matrix[i][j].first = 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            maxValue = max(maxValue, matrix[i][j].first);
        }
    }
    printf("%.6f\n", maxValue);
    return 0;
}