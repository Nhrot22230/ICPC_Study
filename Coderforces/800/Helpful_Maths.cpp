#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

void solve(){
    vector<int> nums;
    string s1;
    cin >> s1;

    for(int i=0; i<s1.length(); i++){
        if(s1[i] == '+') continue;
        nums.push_back(s1[i] - 48);
    }
    
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size(); i++){
        cout << nums[i];
        if(i<nums.size()-1)cout <<'+';
    }
    cout << endl;
}

int main(){
    int t=1;
    //cin >> t;
    while(t--) solve();

    return 0;
}