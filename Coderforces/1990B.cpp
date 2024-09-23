#include <bits/stdc++.h>
#define ll long long
using namespace std;

void Solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> nums(n, 1);
    for(int i=x; i<n; i++) nums[i] = -1;
    for(int i=(y-2); i>=0; i--) nums[i] = -1;

    for(auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int t=1;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
