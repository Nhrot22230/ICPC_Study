#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int **grid = nullptr;
int maxRow, maxCol;

int backTracking(int **grid, int posI, int posJ){
    int i, j;
    for(i = posI; i<maxRow && grid[i][posJ] == 0; i++);

    for(i = posI; i>=0 && grid[i][posJ] == 0; i--);

    for(j = posJ; j<maxCol && grid[posI][j] == 0; j++);

    for(j = posJ; j>=0 && grid[posI][j] == 0; j--);
    
}

int main(){
    cin >> maxRow >> maxCol;
    grid = new int *[maxRow] {};
    for(int i=0; i<maxRow; i++) grid[i] = new int [maxCol] {};

    vector<pair<int, int>> starting_points (maxRow*maxCol);

    for(int i=0; i<maxRow; i++){
        for(int j=0; j<maxCol; j++){
            cin >> grid[i][j];
            starting_points[grid[i][j] - 1] = make_pair(i, j);
        }
    }

    // for(int i=0; i<maxRow*maxCol; i++){
    //     cout << i+1 << ": "<< starting_points[i].first << " " << starting_points[i].second << endl;
    // }



    return 0;
}