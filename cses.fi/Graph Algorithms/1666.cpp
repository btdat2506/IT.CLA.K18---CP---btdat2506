#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m;
bool visited[200010];
vector <ll> edge[200010], res;

void dfs(ll u)
{
    visited[u] = 1;
    for(ll v: edge[u])
    if (!visited[v])
    dfs(v);
}

void process()
{
    For(i, 1, n)
    if (!visited[i])
    {
        dfs(i);
        res.push_back(i);
    }
    cout << res.size() - 1 << "\n";
    For(i, 1, res.size() - 1)
    cout << res[i-1] <<  ' ' << res[i] << "\n";
}

void input()
{
    cin >> n >> m;
    For(i, 1, m)
    {
        ll u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
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