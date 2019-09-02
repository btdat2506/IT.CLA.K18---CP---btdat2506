#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct dt
{
	ll idx = 0, road = 0;
};

dt pros[100010];
ll m, n, k, d[100010];
vector <ll> edge[100010];

void dj()
{
	priority_queue <ii, vector<ii>, cmp> pq;
	pq.push(ii(1, 0));
	d[1] = 0;
	while (!pq.empty())
	{
		ll u = pq.top().x, du = pq.top().y;
		pq.pop();
		if (du != d[u]) continue;
		for(ll i = 0; i < edge[u].size(); i++)
		{
			ll v = edge[u][i];
			if (d[v] > d[u] + 1)
			{
				d[v] = d[u] + 1;
				pq.push(ii(d[v], v));
			}
		}
	}
}

void process()
{
	For(i, 0, 100009) d[i] = INT64_MAX;
	dj();
	For(i, 1, n)
	pros[i].idx = i, pros[i].road = d[i];
}

void input()
{
	cin >> n >> m >> k;
	For(i, 1, m)
	{
		ll x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}