#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

const int N = 1003, oo = 0x3c3c3c3c;
ll n, m, S, T, d[N], c[N][N], f[N][N], dfs[N], Time = 0;
vector <ll> a[N];

bool bfs()
{
	memset(d, 0, sizeof(d));
	queue <ll> qu;
	qu.push(S);
	d[S] = 1;
	while (!qu.empty())
	{
		ll u = qu.front();
		qu.pop();
		if (u == T) return 1;
		for(ll v: a[u])
		if (!d[v] && f[u][v] < c[u][v])
		{
			qu.push(v);
			d[v] = d[u] + 1;
		}
	}
	return 0;
}

ll visit(ll u, ll Min)
{
	if (u == T) return Min;
	if (dfs[u] != Time) dfs[u] = Time; else return 0;
	for(ll v: a[u])
	{
		if (f[u][v] < c[u][v] && dfs[v] != Time && d[v] == d[u] + 1)
		{
			ll x = visit(v, min(Min, c[u][v] - f[u][v]));
			if (x)
			{
				f[u][v] += x;
				f[v][u] -= x;
				return x;
			}
		}
	}
	return 0;
}

int main()
{
	cin >> n >> m >> S >> T;
	For(i, 1, m)
	{
		ll x, y, z;
		cin >> x >> y >> z;
		a[x].push_back(y);
		a[y].push_back(x);
		c[x][y] = z;
	}
	ll sum = 0;
	while (bfs())
	while (ll x = (Time++, visit(S, oo)))
	sum += x;
	cout << sum << "\n";
}