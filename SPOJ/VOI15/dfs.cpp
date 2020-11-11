#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

const ll N = 100010;
ll n, m, visited[N];
vector <ll> edge[N];

void dfs(ll u)
{
	visited[u] = 1;
	for(ll v: edge[u]) 
	if (!visited[v]) dfs(v);	
}

void process()
{
	For(i, 1, n)
	if (!visited[i])
	dfs(i);
}

void input()
{
	cin >> n >> m;
	For(i, 1, n)
	{
		ll u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u); //directional
	}
}

int main()
{
	ios::sync_with_stdio(); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}