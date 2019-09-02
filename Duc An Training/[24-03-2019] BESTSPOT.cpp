#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define x first
#define y second

clock_t start = clock();

typedef pair <ll, ll> ii;

ll n, k, m, d[505][505], f[505];
vector <ll> a[505], cost[505];

struct cmp
{
	bool operator () (const ii &L, const ii &R)
	{
		return L.x > R.x;
	}
};

void dj(ll s)
{
	priority_queue <ii, vector<ii>, cmp> pq;

	For(i, 1, n) d[s][i] = INT64_MAX;
	d[s][s] = 0;
	pq.push(ii(0, s));
	while(pq.size() != 0)
	{
		ll c1 = pq.top().x, 
		   u = pq.top().y;
		pq.pop();
		if (c1 != d[s][u]) continue;
		for(ll i = 0; i < a[u].size(); i++)
		{
			ll v = a[u][i], w = cost[u][i];
			if (d[s][v] > d[s][u] + w)
			{
				d[s][v] = d[s][u] + w;
				pq.push(ii(d[s][v], v));
			}
		}
	}
}

void process()
{
	For(i, 1, n) dj(i);
	ll mn = INT64_MAX, pos = -1;
	For(i, 1, n)
	{
		ll total = 0;
		For(j, 1, k) total += d[i][f[j]];
		if (total < mn) mn = total, pos = i;
	}
	cout << pos << endl;
}

void input()
{
	cin >> n >> k >> m;
	For(i, 1, k) cin >> f[i];
	For(i, 1, m)
	{
		ll u, v, c;
		cin >> u >> v >> c;
		a[u].push_back(v);
		a[v].push_back(u);
		cost[u].push_back(c);
		cost[v].push_back(c);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
	//cout << "TIME: " << double(clock()-start) / CLOCKS_PER_SEC << endl;
}