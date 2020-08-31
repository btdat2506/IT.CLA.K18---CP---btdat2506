#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, res, ans;
bool visited[200010];
vector <ll> edge[200010];
set <ii> inp;

void dfs(ll u)
{
    visited[u] = 1; res++;
    for(ll v: edge[u])
    if (!visited[v])
    dfs(v);
}

void process()
{
    for(ii t: inp)
    {
        ll u = t.first, v = t.second;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    For(i, 1, n)
    if (!visited[i])
    {
        res = 0;
        dfs(i);
        ans = max(ans, res);
    }
    cout << ans << "\n";
}

void input()
{
    cin >> n >> m;
    For(i, 1, m)
    {
        ll u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        inp.insert(ii(u, v));
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