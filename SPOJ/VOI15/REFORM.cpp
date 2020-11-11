#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, cnt, ans, Time, visited[100010], Num[100010], low[100010];
vector <ll> edge[100010];

void visit(ll u, ll p)
{
	Num[u] = low[u] = ++Time;
	for(ll v: edge[u])
	{
		if (v == p) continue;
		if (Num[u])
			low[u] = min(low[u], Num[v]);
		else
		{
			visit(v, p);
			low[v] = min(low[u], low[v]);
			if (low[v] <= Num[v])
		}
	}
}

void process()
{
	For(i, 1, n)
	if (!visited[i])
	{
		cnt++;
		visit(i, i);
	}


}

void input()
{
	cin >> n >> m;
	For(i, 1, m)
	{
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}