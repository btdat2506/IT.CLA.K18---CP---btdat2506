#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

const ll N = 20;
ll n, m, num[N];
vector <ll> edge[N], res;

void dfs(ll u)
{
    for(ll v: edge[u])
    if (!num[v])
    {
        num[v] = num[u] + 1;
        dfs(v);
    }
}

void process()
{
    For(i, 1, n)
    if (!num[i] && res.empty())
    {
        res.push_back(i);
        num[i] = 1;
        dfs(i);
    }
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
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}