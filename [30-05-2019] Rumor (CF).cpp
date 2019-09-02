#include <bits/stdc++.h>

//https://codeforces.com/problemset/problem/893/C

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, ans = 0, cost[100010], visited[100010];
vector <ll> edge[100010];

ll bfs(ll i)
{
	ll res = cost[i];
	queue <ll> q;
	q.push(i);
	while (q.size() != 0)
	{
		i = q.front();
		visited[i] = 1;
		res = min(res, cost[i]);
		q.pop();
		for(auto k: edge[i])
		if (!visited[k]) q.push(k);
	}
	return res;
}

void process()
{
	For(i, 1, n)
	if (!visited[i])
	{
		visited[i] = 1;
		if (edge[i].size() == 0) ans += cost[i];
		else ans += bfs(i);
	}
	cout << ans << endl;
}

void input()
{
	cin >> n >> m;
	For(i, 1, n) cin >> cost[i];
	For(i, 1, m)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
}

void init()
{
	For(i, 0, 100010)
	cost[i] = 0,
	visited[i] = 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	init();
	input();
	process();
}