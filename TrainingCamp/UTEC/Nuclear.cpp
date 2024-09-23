#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 200 + 7;
const int MAX_XOR = 2048;
vector<vector<vector<bool>>> dp(MAX_N, vector<vector<bool>>(MAX_N, vector<bool>(MAX_XOR, false)));
vector<vector<bool>> dp2(MAX_N, vector<bool>(MAX_XOR, false));

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    if ( k > n ) {
        cout << -1 << endl;
        return 0;
    }
    // Inicialización para el DP con exactamente k elementos.
    // dp[i][j][x] = true si podemos obtener XOR = x usando exactamente j elementos de los primeros i elementos.
    dp[0][0][0] = true;

    // Rellenamos la tabla dp.
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int x = 0; x < MAX_XOR; ++x) {
                // Si no usamos el i-ésimo elemento, el estado no cambia.
                dp[i][j][x] = dp[i - 1][j][x];
                // Si estamos considerando usar el i-ésimo elemento y aún tenemos capacidad para seleccionar más elementos.
                if (j > 0) {
                    // Podemos obtener el XOR x si podemos obtener XOR = x ^ a[i-1] con j-1 elementos de los primeros i-1 elementos.
                    dp[i][j][x] = dp[i][j][x] || dp[i - 1][j - 1][x ^ a[i - 1]];
                }
            }
        }
    }

    dp2[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x < MAX_XOR; x++) {
            if (dp2[i - 1][x]) {
                dp2[i][x ^ a[i - 1]] = true;
                dp2[i][x] = true;
            }
        }
    }

    int ans = 0;
    for (int x = 0; x < MAX_XOR; x++) {
        if (dp2[n][x]) ans = max(ans, x);
    }

    int ans2 = -1;
    for (int x = 0; x < MAX_XOR; ++x) {
        if (dp[n][k][x]) {
            ans2 = max(ans2, x);
        }
    }

    if (ans == ans2) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}
