#include <bits/stdc++.h>
 
using namespace std;
 
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
 
ll n, m, cnt1, cnt, low[100010], num[100010];
vector <ll> db[100010];
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
	if (num[u] == low[u])
	{
		ll v = -1, siz = 0;
		while (u != v)
		{
			v = st.top();
			st.pop();
			num[v] = low[v] = INT64_MAX;
			siz++;
		}
		if (siz == 1) num[v] = low[v] = -1;
	}
}
 
void process()
{
	For(i, 1, n)
	if (!num[i]) visit(i);
	queue <ll> ans;
	For(i, 1, n)
	if (num[i] == INT64_MAX && low[i] == INT64_MAX) ans.push(i);
	cout << ans.size() << endl;
	while (!ans.empty())
	{
		cout << ans.front() << ' ';
		ans.pop();
	}
}
 
int main()
{
	cin >> n >> m;
	For(i, 1, m)
	{
		ll x, y;
		cin >> x >> y;
		db[x].push_back(y);
	}
	process();
} 