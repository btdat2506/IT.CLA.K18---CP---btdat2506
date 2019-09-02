#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

void visit(ll u)
{
	low[u] = num[u] = ++cnt1;
	for(auto v: db[u])
	if (num[v])
		low[u] = min(low[u], num[v]);
	else
	{
		visit(v);
		low[u] = min(low[u], low[v]);
	}
	if (low[u] == num[u])
	{
		cnt++;
		ll v = -1;
		while (u != v)
		{
			v = st.top();
			st.pop();
			low[u] = num[v] = INT64_MAX;
		}
	}
}

void process()
{
	For(i, 1, n)
	if (!visited[i]) visit(i);
	cout << ans << endl;
}

void input()
{
	cin >> n >> m;
	For(i, 1, m)
	{
		ll x, y;
		cin >> x >> y;
		db[x].push_back(y);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}