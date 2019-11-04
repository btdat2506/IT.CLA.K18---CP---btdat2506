#include <bits/stdc++.h>

using namespace std;

int n, k, a[103][103];
long long res;
char s[53];
multiset<long long> m[52];
vector<long long> q[52];

int main() {
    //freopen("WORDS.INP", "r", stdin);
    //freopen("WORDS.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];

    for (int r = 1; r <= n; r++)
        for (int i = 1; i <= n; i++) {
            long long s = 0;
            for (int j = i, l = 1; j <= n && l <= 50; j++, l++) {
                s = (s << 1) + a[r][j];
                m[l].insert(s);
            }
        }

    cin >> k;
    while (k--) {
        cin >> s + 1;

        n = strlen(s + 1); long long x = 0;
        for (int i = 1; i <= n; i++) x = (x << 1) + s[i] - '0';

        q[n].push_back(x);
    }

    for (int l = 1; l <= 50; l++) {
        sort(q[l].begin(), q[l].end());

        if (q[l].size() > 0) {
            res += m[l].count(q[l][0]);
            for (int i = 1; i < q[l].size(); i++)
                if (q[l][i] > q[l][i - 1]) res += m[l].count(q[l][i]);
        }
    }

    cout << res;
}
