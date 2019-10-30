#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define MOD 998244353
#define For(i, a, b) for(ll i = a; i <= b; i++)

typedef pair<ll, ll> ii;

bool visited[300010];
ll n, m, ans = 1, val[300010];
vector <ll> edge[300010];

ll bfs(ll st)
{
	ll cnt_x = 1, cnt_y = 0;
	val[st] = 1;
	visited[st] = 1;
	queue <ll> qu;
	qu.push(st);
	while (!qu.empty())
	{
		ll u = qu.front();
		qu.pop();
		for(ll v: edge[u]) 
		if (!visited[v])
		{
			visited[v] = 1;
			val[v] = (val[u] % 2 == 0) ? 1 : 2;
			if (val[v] % 2 == 1) cnt_x++; else cnt_y++;
			qu.push(v);
		}
		else
			if (val[v] == val[u]) return 0;
	}
	ll cnt1 = 1, cnt2 = 1;
	For(i, 1, cnt_x) (cnt1 *= 2) %= MOD;
	For(i, 1, cnt_y) (cnt2 *= 2) %= MOD;
	return (cnt1 + cnt2) % MOD;
}

void process()
{
	For(i, 1, n)
	if (!visited[i])
		(ans *= bfs(i)) %= MOD;
	cout << ans << "\n";
}

void input()
{
	cin >> n >> m;
	For(i, 1, m) 
	{
		ll x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}