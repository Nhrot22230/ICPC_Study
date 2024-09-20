#include<bits/stdc++.h>

using namespace std;

void Solve(int N) {
  vector<int> candies(N);
  int sum = 0;
  for(int i=0; i<N; ++i) {
    cin >> candies[i];
    sum += candies[i];
  }

  int avg = sum/N;
  if(sum != avg*N) {
    cout << -1 << '\n';
    return;
  }

  int ans = 0;
  for(int i=0; i<N; ++i) if(candies[i] < avg) ans += avg - candies[i];
  cout << ans << '\n';
}

int main() {
  int N;
  while(cin >> N && N !=-1) Solve(N);
  return 0;
}
