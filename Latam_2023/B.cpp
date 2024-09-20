#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	n = 3 * n;
	map<int, int> nums;
	while(n--) {
		int ga; cin >> ga;
		nums[ga];
		nums[ga] = nums[ga] + 1;
	}
	for(auto e : nums) {
		if(e.second%3) {
			cout << "Y" << endl;
			return 0;
		}
	}

	cout << "N" << endl;

	return 0;
}
