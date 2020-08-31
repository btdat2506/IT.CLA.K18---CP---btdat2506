#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

bool valid = 1;
ll n, m, visited[100010];
vector <ll> edge[200010];

void dfs(ll u)
{
    if (!valid) return;
    for(ll v: edge[u])
    if (!visited[v])
    {
        visited[v] = 3 - visited[u];
        dfs(v);
    }
    else
    {
        if (visited[v] == visited[u])
        {
            valid = 0;
            return;
        }
    }
}

void process()
{
    For(i, 1, n)
    if (!visited[i])
    {
        visited[i] = 1;
        dfs(i);
        if (!valid) break;
    }
    if (valid)
    {
        For(i, 1, n)
        cout << visited[i] << ' ';
    }
    else
    {
        cout << "IMPOSSIBLE" << "\n";
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
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}