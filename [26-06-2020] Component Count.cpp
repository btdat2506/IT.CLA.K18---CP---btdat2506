#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define For(i, a, b) for(ll i = a; i < b; i++)

ll n, m;
bool visited[1010];
map <ii, bool> mp;
vector <ll> edge[1010];

void dfs(ll u)
{
    visited[u] = 1;
    for(ll v: edge[u])
    if (!visited[v])
    dfs(v);
}

void process()
{
    For(i, 0, n)
    if (!visited[i])
    {
        dfs(i);
        ans++;
    }
    cout << ans << "\n";
}

void input()
{
    cin >> n >> m;
    For(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        if (mp[ii(min(u, v), max(u, v))] == 0)
        {
            mp[ii(min(u, v), max(u, v))] = 1;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
    }
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}