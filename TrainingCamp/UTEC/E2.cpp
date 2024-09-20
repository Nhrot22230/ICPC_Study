#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll MAX = 2e5 * 1e9;

bool check(const vector<ll> &arr, const int k, ll cur_max) {
	int cont = 0;
	ll sum = 0;

	for (int ga : arr) {
		if (ga > cur_max) return false;
		if (sum + ga > cur_max) {
			cont++;
			sum = 0;
		}
		sum += ga;
	}
	if (sum > 0) cont++;

	return cont <= k;
}

int main() {
	int n, k; cin >> n >> k;
	vector<ll> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];

	ll l = 1, r = MAX;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (check(nums, k, mid)) r = mid;
		else l = mid + 1;
	}

	cout << l << endl;
}
