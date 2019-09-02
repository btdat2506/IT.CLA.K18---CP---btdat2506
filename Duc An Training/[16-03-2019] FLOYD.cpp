#include <bits/stdc++.h>

using namespace std;

clock_t start = clock();

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define x first
#define y second

struct request
{
    ll u = 0, v = 0;
    bool c = 0;
};

typedef pair <ll, ll> ii;

struct Comparison
{
    bool operator() (const ii &L, const ii &R)
    {
        return L.x > R.x;
    }
};

request req[10000];
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
    For(i, 1, q)
    {
        dj(req[i].u, req[i].v);
        if (d[req[i].v] == INT64_MAX) cout << 0 << endl; else
        if (!req[i].c) cout << d[req[i].v] << endl; else
        {
            vector <ll> ans;
            ll pos = req[i].v;
            for(; pos != req[i].u;)
            {
                ans.push_back(pos);
                pos = trace[pos];
            }
            cout << ans.size()+1 << ' ' << req[i].u << ' ';
            for(ll i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << ' ';
            cout << endl;
        }
    }
}

void input()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> v >> e >> q;
    For(i, 1, e)
    {
        ll q1, q2, q3;
        cin >> q1 >> q2 >> q3;
        edge[q1].push_back(q2);
        edge[q2].push_back(q1);
        cost[q1].push_back(q3);
        cost[q2].push_back(q3);
    }
    For(i, 1, q)
    {
        ll q1, q2, q3;
        cin >> q1 >> q2 >> q3;
        req[i].c = q1,
        req[i].u = q2,
        req[i].v = q3;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    input();
    process();
    //cout << "TIME: " << double(clock()-start) / CLOCKS_PER_SEC << endl;
    return 0;
}
