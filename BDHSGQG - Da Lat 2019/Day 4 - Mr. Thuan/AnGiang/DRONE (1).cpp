#include <bits/stdc++.h>

using namespace std;

int n, k, c[3003], a[3003];

int main() {
    //freopen("DRONE.INP", "r", stdin);
    //freopen("DRONE.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector< vector<int> > f(n + 3, vector<int>(k + 3, -1));

    f[1][0] = c[1];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < k; j++) if (f[i][j] > -1)
            for (int l = i + 1; l <= min(n, i + a[i]); l++)
                f[l][j + 1] = max(f[l][j + 1], f[i][j] + c[l]);

    cout << f[n][min(n - 1, k)];
}
