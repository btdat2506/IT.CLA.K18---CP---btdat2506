#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, cnt1, cnt, low[10010], num[10010];
vector <ll> db[10010];
stack <ll> st;

void visit(ll u)
{
	low[u] = num[u] = ++cnt1;
	st.push(u);
	for(ll v: db[u])
	if (num[v])
		low[u] = min(low[u], num[v]);
	else
	{
		visit(v);
		low[u] = min(low[u], low[v]);
	}
	if (num[u] > low[u])
	{
		cnt++;
		ll v = -1;
		while (u != v)
		{
			v = st.top();
			st.pop();
			num[v] = low[v] = INT64_MAX;
		}
	}
}

void process()
{
	For(i, 1, n)
	if (!num[i]) visit(i);
	cout << cnt << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	For(i, 1, m)
	{
		ll x, y;
		cin >> x >> y;
		db[x].push_back(y);
	}
	process();
}