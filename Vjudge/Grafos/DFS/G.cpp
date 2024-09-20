#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int V = 501;

int grado_nodo[V] {};
bool grafo[V][V] {};
char solution[V] {};
 
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		grafo[x][y] = grafo[y][x] = 1;
		grado_nodo[x]++;
		grado_nodo[y]++;
	}

	for(int i = 1; i <= n; i++) if(grado_nodo[i] == n - 1) solution[i] = 'b';
	
    for(int i = 1; i <= n; i++) {
		if(!solution[i]) {
			solution[i] = 'a';
			for(int j = 1; j <= n; j++) if(!solution[j]) solution[j] = grafo[i][j] ? 'a' : 'c';	
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			if((abs(solution[i] - solution[j]) == 2 && grafo[i][j]) || (abs(solution[i] - solution[j]) < 2 && !grafo[i][j])) {
				cout << "No" <<endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
    for(int i = 1; i <= n; i++) cout << solution[i];
    cout << endl;
	return 0;
}