#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, cv_count, Time, bridges, low[10010], num[10010], cut_vertices[10010];
vector <ll> db[10010];

void visit(ll u, ll p)
{
	ll baby_edges = 0;
	low[u] = num[u] = ++Time;
	for(ll v: db[u])
	if (v != p)
	{
		if (num[v])
			low[u] = min(low[u], num[v]);
		else
		{
			visit(v, u);
			low[u] = min(low[u], low[v]);
			baby_edges++;
			if (low[v] >= num[v])
				bridges++;
			if (u == p)
			{if (baby_edges == 2)
				cut_vertices[u] = 1;}
			else
			if (low[v] >= num[u])
				cut_vertices[u] = 1;
		}
	}
}

void process()
{
	For(i, 1, n)
	if (!num[i]) visit(i, i);
	For(i, 1, n)
	if (cut_vertices[i]) cv_count++;
	cout << cv_count << ' ' << bridges << endl;
}

void input()
{
	cin >> n >> m;
	For(i, 1, m)
	{
		ll x, y;
		cin >> x >> y;
		db[x].push_back(y);
		db[y].push_back(x);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}