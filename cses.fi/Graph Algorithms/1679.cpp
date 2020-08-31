#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

bool valid = 1;
ll n, m, visited[100010];
vector <ll> edge[100010];
stack <ll> tpsrt;

void dfs(ll u, ll color[])
{
    if (!valid) return;
    color[u] = 1; //visited, but not done
    for (ll v: edge[u])
    if (color[v] == 0)
        dfs(v, color);
    else
    if (color[v] == 1)
        valid = 0;
    color[u] = 2;
}

bool isAcrylic()
{
    ll color[100010];
    memset(color, 0, sizeof(color));
    For(i, 1, n)
    if (!color[i]) dfs(i, color);
    return valid;
}

void topo_sort(ll u)
{
    visited[u] = 1;
    for(ll v: edge[u])
    if (!visited[v]) 
        topo_sort(v);
    tpsrt.push(u);
}

void process()
{
    if (isAcrylic())
    {
        For(i, 1, n)
        if (!visited[i] && valid)
            topo_sort(i);
        while (!tpsrt.empty())
        {
            cout << tpsrt.top() << ' ';
            tpsrt.pop();
        }
    }
    else
        cout << "IMPOSSIBLE" << "\n";
}

void input()
{
    cin >> n >> m;
    For(i, 1, m)
    {
        ll u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
}

int main()
{
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}