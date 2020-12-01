#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, b) for(ll i = 0; i < b; i++)

const ll N = 100010;
ll n, m, cnt, ans, Time, node_cnt[4], Num[N], low[N], child[N], visited[N];
vector <ll> edge[N];
vector <ii> bridges;

void dfs(ll u, ll &cnt)
{
	visited[u] = 1;
	node_cnt[cnt]++;
	for(ll v: edge[u])
	if (!visited[v])
	dfs(v, cnt);
}

void visit(ll u, ll p)
{
	Num[u] = low[u] = ++Time;
	child[u] = 1;
	for(ll v: edge[u])
	if (v != p)
	{
		if (Num[v])
		{
			low[u] = min(low[u], Num[v]);
		}
		else
		{
			visit(v, u);
			child[u] += child[v];
			low[u] = min(low[u], low[v]);
			if (low[v] > Num[u])
			bridges.push_back(ii(u, v));
		}
	}
}

void process()
{
	For(i, 1, n)
	if (!visited[i])
	{
		cnt++;
		if (cnt > 2)
		{
			cout << 0 << "\n";
			return;
		}
		dfs(i, cnt);
	}
	if (cnt == 2)
	{
		For(i, 1, n)
		if (!Num[i]) visit(i, i);
		cout << (m - bridges.size()) * node_cnt[1] * node_cnt[2];
	}
	if (cnt == 1)
	{
		visit(1, 1);
		ll res = (m - bridges.size()) * (n * (n - 1)/2 - m);
		for(ii t: bridges)
		{
			ll u = t.first, v = t.second;
			res += (child[v]) * (n - child[v]) - 1; //only v is accepted
		}
		cout << res << '\n';
	}
}

void input()
{
	cin >> n >> m;
	For(i, 1, m)
	{
		ll u, v;
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