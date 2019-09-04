#include <bits/stdc++.h>
 
using namespace std;
 
clock_t start = clock();
 
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define x first
#define y second
 
typedef pair <ll, ll> ii;
 
struct Comparison
{
    bool operator() (const ii &L, const ii &R)
    {
        return L.x > R.x;
    }
};
 
ll req_u, req_v;
ll v, e, q, d[10000], trace[10000];
bool freed[10000];
vector <ll> edge[10000], cost[10000];
 
void dj(ll u, ll finish)
{
    For(i, 0, 9999) freed[i] = 1;
    memset(trace, 0, sizeof(trace));
    priority_queue <ii, vector<ii>, Comparison> pq;
 
    For(i, 0, v) freed[i] = 1;
    For(i, 0, v) d[i] = INT64_MAX;
    d[u] = 0, trace[u] = u, freed[u] = 0;
    pq.push(ii(0, u));
 
    while (pq.size() != 0)
    {
        u = pq.top().y;
        pq.pop();
        freed[u] = 0;
        if (u == finish) break;
        for(ll i = 0; i < edge[u].size(); i++)
        {
            ll v1 = edge[u][i];
            if (freed[v1] && d[v1] > d[u] + cost[u][i])
            {
                d[v1] = d[u] + cost[u][i];
                trace[v1] = u;
                pq.push(ii(d[v1], v1));
            }
        }
    }
}
 
 
void process()
{
    dj(req_u, req_v);
    if (d[req_v] == INT64_MAX)
}
 
void input()
{
    cin >> v >> e;
    For(dem, 1, e)
    {
        ll v1, v2, leng_th;
        cin >> v1 >> v2 >> leng_th;
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
        cost[v1].push_back(leng_th);
        cost[v2].push_back(leng_th);
    }
    cin >> req_u >> req_v;
}
 
void reset()
{
    v = 0, e = 0, req_u = 0, req_v = 0;
    For(i, 0, 10009) 
    {
        edge[i].clear();
        cost[i].clear();
        freed[i] = 1;
        trace[i] = 0;
        leng[i] = INT64_MAX;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll test;
    cin >> test;
    For(dem, 1, test)
    {
        reset();
        input();
        process();
    }
    //cout << "TIME: " << double(clock()-start) / CLOCKS_PER_SEC << endl;
    return 0;
}