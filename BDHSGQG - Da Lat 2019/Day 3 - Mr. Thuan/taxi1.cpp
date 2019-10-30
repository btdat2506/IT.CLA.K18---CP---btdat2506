#include <bits/stdc++.h>

using namespace std;

const long long oo = 1000000009;

int n, m, a[22][22], f[22][(1 << 20) + 20], res;

int TSP(int u, int msk) {
    cout << u << endl;
    if (f[u][msk] > -1) return f[u][msk];
    if (msk == 0) return a[u][0];

    f[u][msk] = oo;
    for (int v = 1; v <= n; v++)
        if ((msk & (1 << (v - 1))) && (v <= m || !(msk & (1 << (v - m - 1))))) {
            int tmsk = msk ^ (1 << (v - 1));
            cout << msk << ' ' << tmsk << endl;
            f[u][msk] = min(f[u][msk], a[u][v] + TSP(v, tmsk));
        }

    return f[u][msk];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n; m = n >> 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) cin >> a[i][j];

    int MSK = (1 << n) - 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= MSK; j++) f[i][j] = -1;

    res = oo;
    for (int i = 1; i <= m; i++)
        res = min(res, a[0][i] + TSP(i, MSK ^ (1 << (i - 1))));

    cout << res;
}
