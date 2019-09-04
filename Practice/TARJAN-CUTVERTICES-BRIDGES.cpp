#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, time_cnt, criticalEdge, cnt_node, low[10010], num[10010];
bool criticalNode[10010];
vector <ll> db[10010];

void visit(ll u, ll p)
{
	ll numchild = 0;
	low[u] = num[u] = ++time_cnt;
	for(ll v: db[u])
	if (v != p)
	{
		if (num[v])
			low[u] = min(low[u], num[v]);
		else
		{
			visit(v, u);
			numchild++;
			low[u] = min(low[u], low[v]);
			if (low[v] >= num[v])
				criticalEdge++;
			if (u == p)
			{
				if (numchild >= 2) 
					criticalNode[u] = 1;
			}
			else
			if (low[v] >= num[u])
				criticalNode[u] = 1;
		}
	}
}

void process()
{
	memset(criticalNode, 0, sizeof(criticalNode));
	For(i, 1, n)
	if (!num[i]) visit(i, i);
	For(i, 1, n)
	if (criticalNode[i]) cnt_node++;
	cout << cnt_node << ' ' << criticalEdge;
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