#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

bool visited[100010];
ll n, m, ans, cost[100010];
vector <ll> db[100010];

ll dfs(ll u)
{
	ll ans = cost[u];
	visited[u] = 1;
	for(ll v: db[u])
	if (!visited[v])
	ans = min(ans, dfs(v));
	return ans;
}

void process()
{
	For(i, 1, n)
	if (!visited[i])
	ans += dfs(i);
	cout << ans << "\n";
}

void input()
{
	cin >> n >> m;
	For(i, 1, n) cin >> cost[i];
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
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	input();
	process();
}