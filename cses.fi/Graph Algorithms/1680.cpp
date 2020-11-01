#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define INF 1e17
#define For(i, a, b) for(ll i = a; i <= b; i++)

const ll N = 100010;
ll n, m, d[N], p[N];
bool visited[N];
vector <ll> edge[N];

void visit(ll u, stack <ll> &t)
{
    visited[u] = 1;
    for(ll v: edge[u])
    if (!visited[v])
    visit(v, t);
    t.push(u);
}

stack <ll> topo_sort()
{
    stack <ll> t;
    For(i, 1, n)
    if (!visited[i]) visit(i, t);
    memset(visited, 0, sizeof(visited));
    return t;
}

void process()
{
    stack <ll> t = topo_sort();
    For(i, 0, n+2) d[i] = 0;
    d[1] = 1;
    while (!t.empty())
    {
        ll u = t.top();
        t.pop();
        for(ll v: edge[u])
        if (d[u] && d[v] < d[u] + 1) 
        //kiểm tra d[u] vì nếu d[u] = 0 thì có nghĩa là nó nằm ở tplt khác
            d[v] = d[u] + 1,
            p[v] = u;
    }
    if (!d[n])
        cout << "IMPOSSIBLE" << "\n";
    else
    {
        t.push(n);
        for (ll v = p[n]; v != 1; v = p[v])
            t.push(v);
        t.push(1);
        cout << d[n] << "\n";
        while (!t.empty())
        {
            cout << t.top() << ' ';
            t.pop();
        }
    }
}

void input()
{
    ll u, v;
    cin >> n >> m;
    For(i, 1, m)
    {
        cin >> u >> v;
        edge[u].push_back(v);
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