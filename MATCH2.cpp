#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define NIL 0
#define INF (1<<28)
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, match[300];
vector <ll> edge[300], cost[300];

bool dfs()
{

}

bool dfs(ll u)
{
	ll i, v, len;
	if (!u)
	{
		for(ll v: edge[u])

	}
}


ll hopcroft_karp()
{
	ll matching = 0, i;
	while (bfs())
	For(i, 1, n)
	if (!match[i] && dfs(i))
	matching++;
}

void process()
{
	For(i, 1, n)
	{
		edge[n+1].push_back(i);
		edge[i].push_back(n+2);
	}
}

void input()
{
	cin >> n;
	ll i, j, c;
	while (cin >> i >> j >> c)
	{
		edge[i].push_back(j);
		cost[i].push_back(c);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}