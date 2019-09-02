#include <bits/stdc++.h>

using namespace std;

clock_t start = clock();

#define For(i, a, b) for(ll i = a; i <= b; i++)
#define ll int64_t
#define x first
#define y second

typedef pair <ll, ll> ii;

ll v, e, req_u, req_v, freed[10010], trace[10010], leng[10010], d[10010];
vector <ll> edge[10010], cost[10010];

struct Comparison
{
    bool operator() (const ii &L, const ii &R)
    {
        return L.x > R.x;
    }
};

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

void Dijisktra(ll u1, ll v1)
{
	priority_queue <ii, vector<ii>, Comparison> pq;
	leng[u1] = 0, freed[u1] = 0, trace[u1] = u1;
	pq.push(ii(0, u1));
	while (pq.size() != 0)
	{
		u1 = pq.top().y;
		pq.pop();
		freed[u1] = 0;
		if (u1 == v1) break;
		for(ll i = 0; i < edge[u1].size(); i++)
		{
			ll v2 = edge[u1][i];
			if (freed[v2] && leng[v2] > leng[u1] + cost[u1][i])
			{
				leng[v2] = leng[u1] + cost[u1][i];
				trace[v2] = u1;
				pq.push(ii(leng[v2], v2));
			}
		}
	}
}

void process()
{
	dj(req_u, req_v);
	if (d[req_v] != INT64_MAX) 
	cout << d[req_v] << endl; else cout << "NO" << endl;
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
		d[i] = 0;
	}
}

void input()
{
	cin >> v >> e;
	For(dem, 1, e)
	{
		ll v1, v2, leng_th;
		cin >> v1 >> v2 >> leng_th;
		edge[v1].push_back(v2);
		cost[v1].push_back(leng_th);
	}
	cin >> req_u >> req_v;
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
//NOTE: Từ A -> B, bài này chỉ có 1 chiều, không có 2 chiều, chỉ khi nào đọc đề các bài như là A <-> B thì mới là đi cả 2 chiều