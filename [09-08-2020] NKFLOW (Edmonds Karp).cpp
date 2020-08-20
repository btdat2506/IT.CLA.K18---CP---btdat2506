#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

vector <ll> a[1010];
ll n, m, s, t, d[1010], c[1010][1010], f[1010][1010];

bool findpath(ll source, ll target)
{
    queue <ll> qu;
    For(i, 1, n)
        d[i] = 0;
    d[source] = 1e11;
    qu.push(source);
    while (!qu.empty())
    {
        ll u = qu.front(); qu.pop();
        if (u == target)
            return true;
        for (ll v: a[u])
        {
            if (d[v] == 0 && c[u][v] > f[u][v])
            {
                d[v] = u;
                qu.push(v);
            }
        }
    }
    return false;
}

void enlarge()
{
    ll u, v, delta = 1e11;
    for (v = t; (u = d[v]) != ((ll) (1e11)); v = u)
        delta = min(delta, c[u][v] - f[u][v]);
    for (v = t; v != s; v = u)
    {
        u = d[v];
        f[v][u] -= delta;
        f[u][v] += delta;
    }
}

ll answer(ll u)
{
    ll r = 0;
    for(ll v: a[u])
        r += f[u][v];
    return r;
}

void process()
{
    while (findpath(s, t))
        enlarge();
    cout << answer(s) << "\n";
}

void input()
{
    cin >> n >> m >> s >> t;
    For(i, 1, m)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(y);
        a[y].push_back(x);
        c[x][y] = z;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}