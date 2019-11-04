#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

int n, a[10004], pt, p;
long long res, b[10004], m;

int bina(int x) {
    int l = 1, r = pt;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (a[m] == x) return m;
        else if (a[m] < x) l = m + 1; else r = m - 1;
    }
    return -1;
}

int main() {
    //freopen("TRIPLE.INP", "r", stdin);
    //freopen("TRIPLE.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);

    a[0] = a[1] - 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[i - 1]) pt++;
        a[pt] = a[i]; b[pt]++;
    }

    for (int i = 1; i <= pt; i++) {
        if (a[i] * 3 == m) res = (res + b[i] * (b[i] - 1) * (b[i] - 2) / 6) % mod;
        else if (m - a[i] - a[i] > a[i]) {
            long long s = m - a[i] - a[i]; p = bina(s);
            if (p > -1) res = (res + (b[i] * (b[i] - 1) / 2) * b[p]) % mod;
        } else break;

        for (int j = i + 1; j <= pt; j++) {
            long long s = m - a[i] - a[j];

            if (s > a[j]) {
                p = bina(s);
                if (p > -1) res = (res + b[i] * b[j] * b[p]) % mod;
            } else if (s == a[j]) res = (res + b[i] * b[j] * (b[j] - 1) / 2) % mod;
            else break;
        }
    }

    cout << res;
}
