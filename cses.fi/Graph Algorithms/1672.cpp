#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

const ll INF = 1e16;
ll n, m, q, d[510][510];

void process()
{
    For(k, 1, n)
    For(i, 1, n)
    For(j, 1, n)
    if (d[i][j] > d[i][k] + d[k][j])
    d[i][j] = d[i][k] + d[k][j];
    For(i, 1, q)
    {
        ll u, v;
        cin >> u >> v;
        if (d[u][v] == INF)
            cout << -1 << "\n";
        else
            cout << d[u][v] << "\n";
    }
}

void input()
{
    ll u, v, c;
    cin >> n >> m >> q;
    For(i, 0, n+2)
    For(j, 0, n+2)
    d[i][j] = INF;
    For(i, 1, n) d[i][i] = 0;
    For(i, 1, m)
    {
        cin >> u >> v >> c;
        if (d[u][v] > c)
        d[u][v] = d[v][u] = c;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}