#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0)

#define debug(x) cout << #x << " = " << x << endl

using namespace std;

const int V = 2*1e5 + 3;
const int INF = 1e6;

int n_vertices, odd_source, even_source;


vector<vector<int>> adj;
vector<int> distances;
void __init__(){
    adj.resize(n_vertices + 2);
    for(int i=0; i <n_vertices + 2; i++) adj[i].clear();
    distances.resize(n_vertices + 2, INF);
    odd_source = n_vertices;
    even_source = n_vertices + 1;
}

void Add(int from, int to){
    adj[from].push_back(to);
    //adj[to].push_back(from);
}

void BFS(int source){
    for(int i=0; i < n_vertices; i++) distances[i] = INF;
    
    distances[source] = -1;
    queue<int> tour;
    tour.push(source);

    while (!tour.empty())
    {
        int u = tour.front(); tour.pop();
        for(int v : adj[u]){
            int d = distances[u] + 1;
            if(d < distances[v]){
                distances[v] = d;
                tour.push(v);
            }
        }
    }
}

void Solve(){
    cin >> n_vertices;
    __init__();


    vector<int> arr(n_vertices + 2);
    
    for (int i = 0; i < n_vertices; i++)
    {
        cin >> arr[i];
        int left  = i - arr[i];
        int right = i + arr[i];
        if(0 <= left && left < n_vertices) Add(left, i);
        if(0 <= right && right < n_vertices) Add(right, i);
        
        if(arr[i] & 1) Add(odd_source, i);
        else Add(even_source, i);
    }

    BFS(odd_source);
    vector<int> odd_minimum_distances = distances;
    
    BFS(even_source);
    vector<int> even_minimum_distances = distances;

    for(int i=0; i< n_vertices; i++){
        if(odd_minimum_distances[i] == INF) odd_minimum_distances[i] = -1;
        if(even_minimum_distances[i] == INF) even_minimum_distances[i] = -1;
    }

    for(int i=0; i < n_vertices; i++){
        if(i > 0) cout << " ";
        if(arr[i] & 1) cout << even_minimum_distances[i];
        else cout << odd_minimum_distances[i];
    }
    cout << endl;
}

int main(void)
{
    fastio;
    int t=1;
    //cin >> t;
    while (t--)
    {
        /* code */
        Solve();
    }
    
    return 0;
}
