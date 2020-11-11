#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define fs first
#define sc second
#define For(i, a, b) for(ll i = a; i <= b; i++)

//9:56am Oct 9th 2020

struct cmp
{
    bool operator () (const ii &L, const ii &R)
    {
        return L.fs > R.fs;
    }
};

const ll N = 100010;
ll n, m, d[N];
vector <ll> edge[N], cost[N];

void dj()
{
    For(i, 0, n+2) d[i] = 1e14;
    priority_queue <ii, vector<ii>, cmp> pq;
    pq.push(ii(d[1] = 0, 1));
    while (!pq.empty())
    {
        ll u = pq.top().sc, 
           du = pq.top().fs;
        pq.pop();
        if (d[u] < du) continue;

        ll cost_min = 1e12;
        for (ll t: cost[u]) 
            cost_min = min(cost_min, t);

        for (ll i = 0; i < edge[u].size(); i++)
        {
            ll v = edge[u][i];
            //cout << u << ' ' << v << ":" << ' ' << d[v] << ' ' << cost_min << ' ' << d[u] - cost_min << ' ';
            if (d[v] > d[u] - cost_min)
            {
                d[v] = d[u] - cost_min;
                pq.push(ii(d[v], v));
            }
        }
    }
}

void spfa()
{
    For(i, 0, n+2) d[i] = 1e14;
    bool inQueue[N]; memset(inQueue, 0, sizeof(inQueue));
    queue <ll> qu;
    qu.push(1); d[1] = 0; inQueue[1] = 1;
    while (!qu.empty())
    {
        ll u = qu.front(); qu.pop(); inQueue[u] = 0;

        ll cost_min = 1e12;
        for(ll t: cost[u])
            cost_min = min(cost_min, t);

        for(ll i = 0; i < edge[u].size(); i++)
        {
            ll v = edge[u][i];
            if (d[v] > d[u] + cost_min)
                d[v] = d[u] + cost_min;
            if (!inQueue[v])
            {
                inQueue[v] = 1;
                qu.push(v);
            }
        }
    }
}

bool bfs(ll val)
{
    //temp
    For(i, 0, n+2) d[i] = 1e14;
    bool inQueue[N]; memset(inQueue, 0, sizeof(inQueue));
    queue <ll> qu;
    qu.push(1); d[1] = 0; inQueue[1] = 1;
    while (!qu.empty())
    {
        ll u = qu.front(); qu.pop(); inQueue[u] = 0;

        ll cost_min = 1e12;
        for(ll t: cost[u])
            cost_min = min(cost_min, t);

        for(ll i = 0; i < edge[u].size(); i++)
        {
            ll v = edge[u][i];
            if (v == n)
            {
                if (d[u] + cost_min > val) 
                    return 0;
            }
            if (d[v] > d[u] + cost_min)
                d[v] = d[u] + cost_min;
            if (!inQueue[v])
            {
                inQueue[v] = 1;
                qu.push(v);
            }
        }
    }
    return 1;
}

ll BFSnBSearch()
{
    ll l = 1, r = 1e14, mid = (l + r) / 2;
    while (l != mid && r != mid)
    {
        if (bfs(mid))
            r = mid;
        else
            l = mid;
        mid = (l + r) / 2;
    }
    For(i, l, r)
    if (bfs(i)) return i;
}

void process()
{
   /*  For(i, 1, n)
    {
        cout << i << "\n";
        for (ll t: edge[i]) cout << t << ' '; cout << "\n";
        for (ll t: cost[i]) cout << t << ' '; cout << "\n";
    } */
    //dj();
    //cout << -d[n] << "\n";
    //spfa();
    cout << BFSnBSearch() << "\n";
}

void input()
{
    ll u, v, c;
    cin >> n >> m;
    For(i, 1, m)
    {
        cin >> u >> v >> c;
        edge[u].push_back(v);
        cost[u].push_back(c);
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
