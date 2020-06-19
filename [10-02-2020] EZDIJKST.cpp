#include <bits/stdc++.h>

using namespace std;

//begin: 09:58 Feb 10 Monday
//end: 

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define inf 1e10
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, st, ed, d[10010];
vector <ll> edge[10010], cost[10010];

struct cmp
{
    bool operator () (const ii &L, const ii &R)
    {
        return L.first > R.first;
    }
};

void dijisktra()
{
    priority_queue <ii, vector <ii>, cmp> pq;
    d[st] = 0;
    pq.push(ii(0, st));
    while (!pq.empty())
    {
        ll du = pq.top().first, u = pq.top().second;
        pq.pop();
        if (du >= d[u]) continue;
        for(ll i = 0; i < edge[u].size(); i++)
        {
            ll v = edge[u][i];
            if (d[v] > d[u] + cost[u][i])
            {
                d[v] = d[u] + cost[u][i];
                pq.push(ii(d[v], v));
            }
        }
    }
}

void process()
{
    For(i, 1, n) d[i] = inf;
    dijisktra();
}

void input()
{
    cin >> n >> m;
    For(i, 1, m)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        edge[u].push_back(v);
        edge[v].push_back(u);
        cost[u].push_back(c);
        cost[v].push_back(c);
    }
    cin >> st >> ed;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        input();
        process();
    }
}