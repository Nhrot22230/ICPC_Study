#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0)

#define debug(x) cout << #x << " = " << x << endl
#define all(v) v.begin(), v.end()
#define PLL pair<ll,ll>
#define PII pair<int,int>

using namespace std;

ll bSearch(const vector<ll>& arr, ll target) {
    ll left = 0;
    ll right = arr.size() - 1;

    ll index = -1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            index = mid;
            break;
        } else if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    if(index == -1) return 0;

    left = index;
    right = arr.size() -1;
    ll continuos_subsequence = 1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;

        if(arr[mid] == target + mid - index){
            if(mid == arr.size() - 1){
                continuos_subsequence = mid - index + 1;
                break;
            }
            if(arr[mid + 1] > arr[mid] + 1){
                continuos_subsequence = mid - index + 1;
                break;
            }
        }

        if(arr[mid] > target + mid - index){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return continuos_subsequence;
}

int main(int argc, char const *argv[])
{
    vector<ll> nums {1,3,7,8,9,10,15};
    cout << bSearch(nums, 7) << endl;
    return 0;
}
