#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)
#define x first
#define y second

typedef pair<ll, ll> ii;

clock_t start = clock();

ll d[12000], freed[12000], ans = 0, n, m;
vector <ll> cost[16000], edge[16000];

struct cmp
{
	bool operator() (const ii &L, const ii &R)
	{
		return L.x > R.x;
	}
};

void prim()
{
	priority_queue <ii, vector<ii>, cmp> pq;

	d[1] = 0, ans = 0;

	pq.push(ii(0, 1));
	while (pq.size() != 0)
	{
		ll u = pq.top().y, du = pq.top().x;
		pq.pop();
		if (du != d[u]) continue;
		ans += d[u], d[u] = 0;
		For(i, 0, edge[u].size())
		{
			ll v1 = edge[u][i];
			if (d[v1] > cost[u][i]) 
			{
				d[v1] = cost[u][i];
				pq.push(ii(d[v1], v1));
			}
		}
	}
}

void process()
{
	For(i, 0, 11000) d[i] = INT64_MAX, freed[i] = 1;
	prim();
	cout << ans << endl;
}

void input()
{
	cin >> n >> m;
	For(i, 1, m+1)
	{
		ll st, ed, cs;
		cin >> st >> ed >> cs;

		edge[st].push_back(ed);
		edge[ed].push_back(st);

		cost[st].push_back(cs);
		cost[ed].push_back(cs);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
	//cout << "TIME: " << double(clock()-start) / CLOCKS_PER_SEC << endl;
}