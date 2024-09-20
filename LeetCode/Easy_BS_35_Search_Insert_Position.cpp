#include <bits/stdc++.h>

using namespace std;
/*
    target = 5
    0 2 4
    nums[med] = 5
    ->  
*/

int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int med;
    while(left <= right){
        med = left + (right - left) / 2;

        if(nums[med] == target) return med;
        if(nums[med] < target) left = med + 1;
        else right = med - 1;
    }
    
    return left;
}

int main(){
    vector <int> nums {1,3,5,6};
    int target; cin >> target;
    cout << searchInsert(nums, target) << endl;
    return 0;
}