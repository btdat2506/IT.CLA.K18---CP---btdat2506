#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef pair<int, int> ii;

int n, t, f[50];
ii a[10004];

int main() {
    //freopen("BANK.INP", "r", stdin);
    //freopen("BANK.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> t;
    for (int i = 1; i <= n; i++) cin >> a[i].ff >> a[i].ss;

    sort(a + 1, a + n + 1, greater<ii>());

    for (int i = 1; i <= n; i++) {
        int x = a[i].ff, time = a[i].ss;
        while (f[time] > 0 && time >= 0) time--;
        if (time >= 0) f[time] = x;
    }

    int res = 0;
    for (int i = 0; i <= t; i++) res += f[i];

    cout << res;
}
