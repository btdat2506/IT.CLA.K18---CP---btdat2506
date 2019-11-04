#include <bits/stdc++.h>

using namespace std;

char c;
int n, a[500005], s[500005], p[500005], res, m;

int bina(int x, int r) {
    int l = 1, res = -1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (s[p[m]] <= x) {
            res = m;
            l = m + 1;
        } else r = m - 1;
    }
    return res;
}

int len(int k) {
    int pos = m, cnt = 0, res = 0;

    while (pos > 0) {
        pos = bina(s[p[pos]] - k, pos - 1);
        if (pos > 0) {
            cnt++;
            if (s[p[pos]] >= k) res = max(res, cnt + (cnt + 1) * k);
        }
    }

    return res;
}
int main() {
    //freopen("BEAUSTR.INP", "r", stdin);
    //freopen("BEAUSTR.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        a[i] = c - '0';
        s[i] = s[i - 1] + int(a[i] == 0);
        if (a[i] == 1) p[++m] = i;
    }

    p[++m] = n;
    for (int i = 0; i <= n; i++) res = max(res, len(i));

    cout << res;
}
