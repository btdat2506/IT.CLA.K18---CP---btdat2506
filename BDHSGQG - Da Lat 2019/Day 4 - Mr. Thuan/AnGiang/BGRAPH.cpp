#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

int n, m, u, v, d[300005];
long long f[300005], res;
vector<int> g[300005];

long long BFS(int u) {
    queue<int> q;
    long long cnt[3];

    q.push(u);
    d[u] = 0; cnt[0] = 1; cnt[1] = 0;

    while (q.size() > 0) {
        u = q.front(); q.pop();

        for (int v:g[u])
            if (d[v] == -1) {
                d[v] = d[u] ^ 1; cnt[d[v]]++;
                q.push(v);
            } else if (d[v] == d[u]) return 0;
    }

    return (f[cnt[0]] + f[cnt[1]]) % mod;
}

int main() {
    //freopen("BGRAPH.INP", "r", stdin);
    //freopen("BGRAPH.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * 2 % mod;
        d[i] = -1;
    }

    res = 1;
    for (int i = 1; i <= n; i++) if (d[i] == -1) {
        res *= BFS(i);

        if (res == 0) {
            cout << 0;
            return 0;
        }
    }

    cout << res;
}
