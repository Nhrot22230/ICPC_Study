#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0);



#define debug(x) cout << #x << " = " << x << endl
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pii pair<int,int>

#define vi vector<int>
#define vl vector<ll>

using namespace std;


void Solve(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int main(void)
{
    fastio;
    int t=1;
    //cin >> t;
    
    auto start = high_resolution_clock::now();
    Solve(1e8);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
    return 0;
}
