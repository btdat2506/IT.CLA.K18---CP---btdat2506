#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define val first
#define max_val second
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, r, t[300], cost[300][300];
pair <ll, ll> f[300][300];

ll max(ll a, ll b, ll c, ll d)
{
    return max(max(a, b), max(c, d));
}

void process()
{
    For(k, 1, n)
    For(i, 1, n)
    For(j, 1, n)
    if (f[i][j].val + f[i][j].max_val > f[i][k].val + f[k][j].val + max(f[i][k].max_val, f[k][j].max_val, f[i][i].max_val, f[j][j].max_val))
    {
        f[i][j].max_val = max(f[i][k].max_val, f[k][j].max_val, f[i][i].max_val, f[j][j].max_val);
        f[i][j].val = f[i][k].val + f[k][j].val;
    }
    For(i, 1, r)
    {
        ll u, v;
        cin >> u >> v;
        cout << f[u][v].val + f[u][v].max_val << "\n";
    }
}

void input()
{
    For(i, 1, n)
    For(j, 1, n)
    f[i][j].val = 1e9;
    cin >> n >> m >> r;
    For(i, 1, n) cin >> f[i][i].max_val;
    For(i, 1, m)
    {
        ll u, v;
        cin >> u >> v >> f[u][v].val;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("CHIPHI.INP", "r", stdin);
    freopen("CHIPHI.OUT", "w", stdout);
    input();
    process();
}