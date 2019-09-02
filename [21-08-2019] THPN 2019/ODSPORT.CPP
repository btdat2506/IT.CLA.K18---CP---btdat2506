#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, q, v[100010], s[100010], query[100010];

ll bfs()
{
	queue <ll> qu;
	For(i, 1, m) if (!matchX[i]) qu.push(i);
	memset(trace, 0, sizeof(trace));
	while (!qu.empty())
	{
		ll u = qu.front();
		qu.pop();
		for(ll i = 0; i < a[u].size(); i++)
		{
			ll v = a[u][i];
			if (trace[v] == 0)
			{
				trace[v] = u;
				if (matchY[v] == 0) return v;
				else qu.push(matchY[v]);
			}
		}
	}
	return 0;
}

void enlarge(ll y)
{
	ll next = 0, x = 0;
	for(; y; y = next)
	{
		x = trace[y],
		next = matchX[x],
		matchX[x] = y,
		matchY[y] = x;
	}
}

void process()
{
	
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> v[i];
	For(i, 1, n)
	cin >> s[i];
	cin >> q;
	For(i, 1, q)
	cin >> query[i];
}

int main()
{
	freopen("ODSPORT.INP", "r", stdin);
	freopen("ODSPORT.OUT", "w", stdout);
	input();
	process();
}