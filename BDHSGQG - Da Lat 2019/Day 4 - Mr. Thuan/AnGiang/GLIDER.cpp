#include <bits/stdc++.h>

using namespace std;

int n, h, x[300005], y[300005], res;

int main() {
    //freopen("GLIDER.INP", "r", stdin);
    //freopen("GLIDER.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> h;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    int hh = h, s = 0;
    for (int i = 1, j = 1; i < n; i++) {
        while (hh > 0 && j <= n) {
            hh -= x[j + 1] - y[j];
            s += y[j] - x[j];
            j++;
        }

        res = max(res, h + s);

        hh += x[i + 1] - y[i];
        s -= y[i] - x[i];
    }

    cout << res;
}
