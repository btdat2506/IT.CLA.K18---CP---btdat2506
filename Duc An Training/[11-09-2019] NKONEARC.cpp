#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, s, t, visited[2010];
vector <ll> edge[2010], edge_rev[2010];

void dfs(ll u)
{
	visited[u] = 1;
	for(ll v: edge[u])
	if (!visited[v])
	dfs(v);
}

void dfs1(ll u)
{
	visited[u] = 0;
	for(ll v: edge_rev[u])
	if (visited[v])
	dfs1(v);
}

void process()
{
	For(i, 1, n)
	if (!visited[i])
	{
		dfs(i);
		s = i;
	}
	For(i, 1, n)
	if (visited[i])
	{
		dfs1(i);
		t = i;
	}
	cout << "YES \n" << t << ' ' << s;
}

void input()
{
	cin >> n >> m;
	For(i, 1, m)
	{
		ll x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge_rev[y].push_back(x);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}