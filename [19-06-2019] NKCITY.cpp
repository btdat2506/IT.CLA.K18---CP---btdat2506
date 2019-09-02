#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

typedef pair<ll, ll> ii;

ll n, m, ans, d[1010];
vector <ll> edge[10010], cost[10010];

struct cmp
{
	bool operator () (const ii &L, const ii &R)
	{
		return L.x > R.x;
	}
};

void prim()
{
	priority_queue <ii, vector<ii>, cmp> pq;
	pq.push(ii(0, 1));
	d[1] = 0, ans = 0;
	while (!pq.empty())
	{
		ll du = pq.top().x, u = pq.top().y;
		pq.pop();
		if (du != d[u]) continue;
		ans = max(ans, d[u]); d[u] = 0;
		for(ll i = 0; i < edge[u].size(); i++)
		{
			ll v = edge[u][i];
			if (d[v] > cost[u][i])
			{
				d[v] = cost[u][i];
				pq.push(ii(d[v], v));
			}
		}
	}
}

void process()
{
	For(i, 0, 1009) d[i] = INT64_MAX;
	prim();
	cout << ans << endl;
}

void input()
{
	cin >> n >> m;
	For(i, 1, m)
	{
		ll u, v, t;
		cin >> u >> v >> t;
		edge[u].push_back(v);
		edge[v].push_back(u);
		cost[u].push_back(t);
		cost[v].push_back(t);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	input();
	process();
}

