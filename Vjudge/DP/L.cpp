#include <bits/stdc++.h>

#define ENDL '\n'
#define ll long long
#define fastio ios_base::sync_with_stdio(false); std::cin.tie(NULL);

using namespace std;


void Solve(void){
    string line;

    vector<int> altitudes;
    while(getline(cin, line)){
        if(line.length() == 0) break;
        
        else{
            int number = stoi(line);
            altitudes.push_back(number);
        }
    }
    
    /* LIS */
    int n = altitudes.size();
    
    vector<int> LIS(n, 1);
    vector<int> path(n, -1);
    LIS[0] = 1;      
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
        {
            int l = altitudes[i] > altitudes[j] ? LIS[j] + 1 : 0;
            if (l > LIS[i])
            {
                LIS[i] = l;
                path[i] = j;
            }
        }

    int max_lis_i = -1;
    int max_val = 0;
    for(int i=0; i<n; ++i){
        if(max_val < LIS[i]){
            max_val = LIS[i];
            max_lis_i = i;
        }
    }

    /* PRINT VALUES */
    cout << "Max hits: " << max_val << endl;

    deque<int> values;
    
    int i = max_lis_i;
    while(i != -1){
        values.push_front(altitudes[i]);
        i = path[i];
    }

    while(! values.empty()){
        int num = values.front();
        values.pop_front();
        cout << num << endl;
    }
}

int main(){
    int t;
    cin >> t;
    cin.get();
    cin.get();

    while (t--)
    {
        Solve();
        if(t) cout << endl;
    }

    

    return 0;
}
