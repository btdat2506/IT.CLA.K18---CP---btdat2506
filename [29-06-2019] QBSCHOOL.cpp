#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

typedef pair <ll, ll> ii;

struct cmp
{
	bool operator () (const ii &L, const ii &R)
	{
		return L.x > R.x;
	}
};

ll n, m, d[6000], cnt[6000], freed[6000];
vector <ll> edge[6000], cost[6000];

void dj()
{
	priority_queue<ii, vector<ii>, cmp> pq;
	pq.push(ii(0, 1));
	d[1] = 0;
	cnt[1] = 1;
	freed[1] = 0;
	while(!pq.empty())
	{
		ll u = pq.top().y, du = pq.top().x;
		pq.pop();
		freed[u] = 0;
		if (u == n) break;
		for(ll i = 0; i < edge[u].size(); i++)
		{
			ll v = edge[u][i];
			if (d[v] == d[u] + cost[u][i]) cnt[v] += cnt[u];
			if (freed[v] && d[v] > d[u] + cost[u][i])
			{
				d[v] = d[u] + cost[u][i];
				cnt[v] = cnt[u];
				pq.push(ii(d[v], v));
			}
		}
	}
	cout << d[n] << ' ' << cnt[n] << endl;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	For(i, 1, n) d[i] = INT64_MAX, cnt[i] = 0, freed[i] = 1;
	For(i, 1, m)
	{
		ll type, u, v, c;
		cin >> type >> u >> v >> c;
		edge[u].push_back(v);
		cost[u].push_back(c);
		if (type == 2)
			edge[v].push_back(u),
			cost[v].push_back(c);
	}
	dj();
}