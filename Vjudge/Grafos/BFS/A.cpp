#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0)

#define debug(x) cout << #x << " = " << x << endl
#define PII pair<int,int>
#define PLL pair<ll,ll>

using namespace std;

const int V = 1e6 + 5;
const int INF = 1e9;

vector<vector< pair<char,int> >> matrix(50);
vector<vector<int>> visited(50);
int dj[8] { 0, 1, 1, 1, 0,-1,-1,-1};
int di[8] {-1,-1, 0, 1, 1, 1, 0,-1};
int h, w;


void __init___(){
    matrix.clear();
    matrix.resize(50);
    for(int i=0; i<50; i++) {
        matrix[i].resize(50, {0,0});
    }
}

bool isNotValid(int i, int j){
    if(i < 0 || j < 0) return true;
    if(i >= h || j >= w) return true;
    return false;
}

void bfs(pair<int ,int> &source){
    queue<pair<int,int>> tour;
    tour.push(source);

    while (not tour.empty())
    {
        pair<int, int> cur = tour.front(); tour.pop();

        char cur_letra = matrix[cur.first][cur.second].first;
        int act_value = matrix[cur.first][cur.second].second;

        for(int i=0; i<8; i++){
            int _i = cur.first  + di[i];
            int _j = cur.second + dj[i];
            if(isNotValid(_i, _j)) continue;
            
            if( int(matrix[_i][_j].first) == int(cur_letra) + 1){
                if(act_value + 1 <= matrix[_i][_j].second) continue;
                //cout << matrix[_i][_j].first << "->";
                matrix[_i][_j].second = act_value + 1;
                tour.push({_i, _j});
            }
        }
    }
    //cout << endl;
}

void solve(int H, int W, int t){
    __init___();
    vector< pair<int,int> > sospechosos;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> matrix[i][j].first;
            if(matrix[i][j].first == 'A'){
                matrix[i][j].second = 1;
                sospechosos.push_back({i,j});
            }
        }
    }

    for(pair<int,int> sus : sospechosos) bfs(sus);


    int max_val = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            max_val = max(max_val, matrix[i][j].second);
        }
    }

    cout << "Case " << t << ": " << max_val << endl;
}

int main(int argc, const char** argv) {
    fastio;
    int t = 1;
    while (true)
    {   
        cin >> h >> w;
        if(h == 0 && w == 0) break;
        solve(h, w, t);
        t++;
    }
    
    
    return 0;
}