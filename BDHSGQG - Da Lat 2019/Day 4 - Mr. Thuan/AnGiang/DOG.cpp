#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef pair<int, int> ii;

vector<int> g[1003];
int n, w[1003], m, res[1003], t, u, v;
bool f[1003][1003], wait[1003];

int main() {
    //freopen("DOG.INP", "r", stdin);
    //freopen("DOG.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    cin >> t;

    f[0][1] = true;
    for (int time = 0; time <= t; time++) {
        for (int u = 1; u <= n; u++) if (f[time][u]) {
            res[u]++; wait[u] = false;
            for (int v:g[u]) if (time + w[v] <= t && !wait[v] && !f[time][v]) {
                f[time + w[v]][v] = true;
                wait[v] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << res[i] << "\n";
}
