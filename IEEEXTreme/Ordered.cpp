#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> nums;
    for(int i=1; i<=n; i++) nums.push_back(i);
    string R;
    cin >> R;
    int cont = 0;
    do{
        bool flag = true;
        for(int i=1; i<n; i++){
            if(R[i-1] == '>'){
                flag = flag && nums[i-1] > nums[i];
            }else{
                flag = flag && nums[i-1] < nums[i];
            }
        }

        for(int i=0; i<n; i++){
            cout << nums[i] << "  ";
        }
        cout << endl;
        if(flag) cont++;
    }
    while(next_permutation(nums.begin(), nums.end()));

    cout << cont << endl;
    return 0;
}