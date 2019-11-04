#include <bits/stdc++.h>

using namespace std;

int n, a[100005], f[100005][14], res;

int ccw(int t, int k) {
    t -= k;
    if (t <= 0) t += 12;
    return t;
}

int main() {
    //freopen("CLOCK.INP", "r", stdin);
    //freopen("CLOCK.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i < 12; i++) f[1][ccw(a[1], i)] = i;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < 12; j++) f[i][ccw(a[i], j)] = f[i - 1][ccw(12, j)] + j;

    res = 1000000009;
    for (int i = 0; i < 12; i++) res = min(res, f[n][ccw(12, i)] + i);

    cout << res;
}
