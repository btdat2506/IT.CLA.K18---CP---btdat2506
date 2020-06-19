#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)


ll a, b;
bool visited[1000];
vector <ll> v, res, tmp;

bool Prime(ll n)
{
    if (n < 2) return 0;
    For(i, 2, sqrt(n))
    if (n % i == 0) return 0;
    return 1;
}

void dfs(ll u)
{
    visited[u] = 1;
    tmp.push_back(v[u]);
    if (v[u] == b)
    {
        if (res.empty() || res.size() > tmp.size()) res = tmp;
        tmp.pop_back();
        return;
    }
    for (ll i = 0; i < v.size(); i++)
    if (!visited[i] && Prime(max(v[i] - v[u], v[u] - v[i])))
    {
        dfs(i);
        visited[i] = 0;
    }
    tmp.pop_back();
}

void process()
{
    memset(visited, 0, sizeof(visited));
    set <ll> got;
    got.insert(2);
    For(i, -2, 2)
    {
        if (Prime(a + i)) got.insert(a + i);
        if (Prime(b + i)) got.insert(b + i);
    }
    for(ll t: got) v.push_back(t);
    //===================================================
    for(ll i = 0; i < v.size(); i++)
    if (v[i] == a) dfs(i);
    //===================================================
    if (res.empty())
    {
        cout << -1 << "\n";
        return;
    }
    cout << res.size() << "\n";
    for(ll t: res)
    cout << t << ' ';
}

void input()
{
    cin >> a >> b;
}

int main()
{
    freopen("LUTRIJA.INP", "r", stdin);
    freopen("LUTRIJA.OUT", "w", stdout);
    input();
    process();
}