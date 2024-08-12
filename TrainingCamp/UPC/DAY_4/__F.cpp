#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> nums(n);

  int maxI = 0;
  int minI = 0;
  int maxH = 0;
  int minH = 1000;

  for(int i=0; i<n; i++) cin >> nums[i];

  for(int i=0; i<n; i++) {
    if (maxH < nums[i]) {
      maxH = nums[i];
      maxI = i;
    }
  }

  int cont = 0;
  for(int i=(n - 1); i>=0; i--) {
    if (minH > nums[i]) {
      minH = nums[i];
      minI = cont;
    }
    cont ++;
  }

  if(maxI > minI) cout << maxI + minI - 1 << endl;
  else cout << maxI + minI << endl;

  return 0;
}
